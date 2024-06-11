import java.util.*;
public class toposort{
	static class Edge{
		int source;
		int destination;
		public Edge(int source,int destination){
			this.source= source;
			this.destination = destination;
		}
	}
	public static void CreateGraph(ArrayList<Edge> graph[]){
		for(int i = 0;i<graph.length;i++){
			graph[i] = new ArrayList<>();
		}

		graph[2].add(new Edge(2, 3));
		graph[3].add(new Edge(3, 1));
		graph[4].add(new Edge(4, 0));
		graph[4].add(new Edge(4, 1));
		graph[5].add(new Edge(5, 0));
		graph[5].add(new Edge(5, 2));
	}
	public static void topodfs(ArrayList<Edge> graph[],int curr,boolean visited[],Stack<Integer> Stack){
		if(visited[curr] == true){
			return;
		}
		visited[curr] = true;
		for(int i = 0;i<graph[curr].size();i++){
			Edge e = graph[curr].get(i);
			if(!visited[e.destination]){
				topodfs(graph,e.destination,visited,Stack);
			}
		}
		Stack.push(curr);
	}
	public static void topo(ArrayList<Edge> graph[]){
		boolean visited[] = new boolean[graph.length];
		Stack<Integer> Stack = new Stack<>();
		for(int i= 0 ;i<graph.length;i++){
			if(!visited[i]){
				topodfs(graph,i,visited,Stack);
			}
		}

		while(!Stack.isEmpty()){
			System.out.print(Stack.pop()+" ");
		}
	}
	public static void main(String[] args){
		int V = 6;
		ArrayList<Edge> graph[] = new ArrayList[V];
		CreateGraph(graph);
		topo(graph);
	}
	
}

import java.util.*;
public class bfs{
	static class Edge{
		int s;
		int d;
		public Edge(int s,int d){
			this.s = s;
			this.d = d;
		}
	}
	  public static void CreateGraph(ArrayList<Edge> graph[]){
        for(int i = 0;i< graph.length;i++){
            graph[i] = new ArrayList<Edge>();
        }
        graph[0].add(new Edge(0,2 ));

        graph[1].add(new Edge(1,2));
        graph[1].add(new Edge(1,7));

        graph[2].add(new Edge(2,8));
        graph[2].add(new Edge(2,2));
        graph[2].add(new Edge(2,1));

        graph[3].add(new Edge(3,2));
        graph[3].add(new Edge(3,5));

    }
	public static void bfs(ArrayList<Edge> graph[],int V){
		Queue<Integer> q = new LinkedList<>();
		boolean visited[] = new boolean[V];
		q.add(0);
		while(!q.isEmpty()){
			int curr = q.remove();
			if(visited[curr] == false){
				System.out.print(curr +" ");
				visited[curr] = true;

				for(int i = 0;i<graph[curr].size();i++){
					Edge e = graph[curr].get(i);
					q.add(e.d);
				}
		}
	}
	}
	public static void main(String[] args) {
        	int V = 9;
       	 	ArrayList<Edge> graph[] = new ArrayList[V];
        	CreateGraph(graph);
        	bfs(graph,V);
        	System.out.println();

    	}

}

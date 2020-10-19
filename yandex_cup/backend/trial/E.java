import java.util.*;
import java.io.*;

public class E {
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        InputReader scanner = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int numberOfConnections = scanner.nextInt();
        Map<Integer, ArrayList<Integer>> nodeToConnections = new HashMap<>();
        Set<Integer> nodes = new HashSet<>();

        for (int i = 0; i < numberOfConnections; ++i) {
            int node = scanner.nextInt();
            int connection = scanner.nextInt();

            ArrayList<Integer> list = nodeToConnections.get(node);

            if (list == null) {
                list = new ArrayList<Integer>();
                nodeToConnections.put(node, list);
            }

            list.add(connection);
            nodes.add(node);

            list = nodeToConnections.get(connection);

            if (list == null) {
                list = new ArrayList<Integer>();
                nodeToConnections.put(connection, list);
            }

            list.add(node);
            nodes.add(connection);
        }

        int clusterIdx = 0;
        int connectedComponents = 0;
        Map<Integer, HashSet<Integer>> clustersToNodes = new HashMap<>();
        Map<Integer, Integer> nodesToClusters = new HashMap<>();

        while (!nodes.isEmpty()) {
            HashSet<Integer> clusterNodes = new HashSet<>();
            Iterator nodesIt = nodes.iterator();
            int node = (int) nodesIt.next();

            Queue<Integer> queue = new LinkedList<>();
            queue.add(node);

            while (!queue.isEmpty()) {
                node = queue.remove();
                clusterNodes.add(node);
                nodes.remove(node);

                ArrayList<Integer> list = nodeToConnections.get(node);

                if (list != null) {
                    for (int adjNode : list) {
                        if (nodes.contains(adjNode)) {
                            queue.add(adjNode);
                        }
                    }
                }
            }
            clustersToNodes.put(clusterIdx, clusterNodes);

            for (int clusterNode: clusterNodes) {
                nodesToClusters.put(clusterNode, clusterIdx);
            }
            ++clusterIdx;
            ++connectedComponents;
        }

        int numberOfRequests = scanner.nextInt();

        for (int i = 0; i < numberOfRequests; ++i) {
            int nodeForDownload = scanner.nextInt();
            int numberOfNodesWithData = scanner.nextInt();
            int cluster = nodesToClusters.get(nodeForDownload);
            Set<Integer> clusterNodes = clustersToNodes.get(cluster);
            List<Integer> nodesWithData = new ArrayList<>();

            for (int j = 0; j < numberOfNodesWithData; ++j) {
                int nodeWithData = scanner.nextInt();
                if (clusterNodes.contains(nodeWithData)) {
                    nodesWithData.add(nodeWithData);
                }
            }

            out.print(nodesWithData.size());

            for (int k = 0; k < nodesWithData.size(); ++k) {
                out.print(" " + nodesWithData.get(k));
            }
            out.println();
            out.flush();
        }
    }
}

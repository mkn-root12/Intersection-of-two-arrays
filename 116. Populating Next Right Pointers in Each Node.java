class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return root;
        }
        LinkedList<Node> q = new LinkedList<>();
        Node last = null;
        q.add(root);
        q.add(null);

        while (true) {
            Node curNode = q.pollFirst();
            if (curNode == null) {
                if (q.size() == 0) {
                    break;
                }
                q.add(null);
                last = null;
            } else {
                if (curNode.left != null) {
                    if (last != null) {
                        last.next = curNode.left;
                    }
                    q.offerLast(curNode.left);
                    q.offerLast(curNode.right);
                    curNode.left.next = curNode.right;
                    last = curNode.right;
                }
            }
        }

        return root;
    }
}

package tree;
import java.util.*;

public class binary_tree {

    Scanner sc = new Scanner(System.in);

    static public class Node{
        Node left;
        Node right;
        int data;
        Node(int d){
            this.data = d;
            right = left = null;
        }
    }

    Node root;

    binary_tree(){
        root = null;
    }

    Node buildTree(Node root){
        System.out.print("enter the data : ");
        int data = sc.nextInt();
        root = new Node(data);

        if(data == -1){
            return null;
        }

        System.out.println("eneter the data for inserting left of " + data );
        root.left = buildTree(root.left);
        System.out.println("enter the data for inserting right of " + data);
        root.right = buildTree(root.right);
        return root;
    }

    Node searchTree(Node root, int d){
        if(root == null){
            Node node = new Node(d);
            return node;
        }
        if(d <= root.data){
            root.left =  searchTree(root.left, d);
        }
        else{
            root.right =  searchTree(root.right, d);
        }
        return root;
    }
// 1 2 -1 -1 3 -1 -1
    void levelOrderTraversal(Node root){

        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        q.add(null);

        while (!q.isEmpty()){
            Node temp = q.peek();  // q.pool()
            q.remove();
            if(temp == null){
                System.out.println();
                if(!q.isEmpty()){
                    q.add(null);
                }
            }
            else{
                System.out.print(temp.data + " ");
                if(temp.left != null){
                    q.add(temp.left);
                }
                if(temp.right != null){
                    q.add(temp.right);
                }
            }
        }
    }

    void inorder(Node root) {
        if(root == null) {
            return ;
        }
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    void preorder(Node root) {
        if(root == null) {
            return ;
        }
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    void postorder(Node root) {
        if(root == null) {
            return ;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }

    int height(Node root){
        if(root == null){
            return 0;
        }
        int left = height (root.left);
        int right = height(root.right);
        return (Math.max(left, right) + 1);
    }



    public static void main(String[] args){

        binary_tree bt = new binary_tree();
//        Node root = new Node(5);
//        root.left = new Node(9);
//        root.right = new Node(7);

        Node root = null;
//        root = bt.buildTree(root);
        root = bt.searchTree(root, 5);
        root = bt.searchTree(root, 10);
        root = bt.searchTree(root, 3);
//        bt.inorder(root);
//        bt.levelOrderTraversal(root);
        System.out.println("path" + bt.height(root));

    }
}

public class Word_Search_2{

  public class Node{
    int word_end=0;
    String word="";
    Node[] childs;
    Node(){
      this.childs=new Node[26];

    }
  }

  Node root=null;
  public void insert(String word){
    Node curr=root;
    int n=word.length();
    for(int i=0;i<n;i++)
    {
       int idx= word.charAt(i)-'a';
       if(curr.childs[idx]==null) curr.childs[idx]=new Node();
       curr=curr.childs[idx];
    }
    curr.word_end++;
    curr.word=word;
  }




















}

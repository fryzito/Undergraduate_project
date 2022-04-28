/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package generador_de_numeros_aleatorios;

/**
 *
 * @author wildr
 */
public class CCuadradoMedio {
    /* ********************* Atributos ********************  */
    private int ai;
    private int an;
    private int ax;
    private int[]alist;
    /* ********************* METODOS  *********************  */
    /* ===================== constructores ================= */
    /* --------------------- sin atributos -------------------*/
    public CCuadradoMedio(){
        ai=3;
        an=2;
        ax=7152;
        alist=new int[100];
    }
    /* --------------------- con atributos -------------------*/
    public CCuadradoMedio(int i,int n,int x,int[]list){
        ai=i;
        an=n;
        ax=x;
        alist=list;
    }
    /* --------------------- Modificadores ------------------- */
    /* ---------------------  Selectores   ------------------- */
    public int i(){
        return ai;
    }
    public int n(){
        return an;
    }
    public int x(){
        return ax;
    }
    public int[]list(){
        return alist;
    }
    /* ===================== Otros Metodos =================== */
    public void GeneradorCM(int i, int n, int x,int[]list){
        String p;
        for(int k=0; k<i; k++){
            int w=(int)Math.pow(x, 2.0);
            String s=String.valueOf(w).toString();
            if(s.length()%2==0){
                int m=s.length()/2;
                p=s.substring(m-n, 2*n);
            }
            else{
                s="0"+s;
                int m=s.length()/2;
                p=s.substring(m-n, 2*n);
            }
            int r=Integer.parseInt(p);
            x=r;
            // guardar datos Ui
            list[k]=r;
       }
    }
    /* --------------------- Modificadores ------------------- */
    public void GeneradorCM(){
        String p;
        for(int k=0; k<ai; k++){
                        System.out.println(ax);
                                    
            int w=(int)Math.pow(ax, 2.0);
            String s=String.valueOf(w).toString();
            if(s.length()%2==0){
                int m=s.length()/2;
                p=s.substring((m-an), (m+an));
                // por que no es p=s.substring((m-an), (2*an)); conp=s.substring((m-an), (m+an));
            }
            else{
                s="0"+s;
                int m=s.length()/2;
                p=s.substring(m-an, m+an);
            }
            
            int r=Integer.parseInt(p);
            ax=r;

            // guardar datos Ui
            alist[k]=r;
       }
    }
}

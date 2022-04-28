/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package generador_de_numeros_aleatorios;

/**
 *
 * @author wildr
 */
public class CGeneradorCongruencial {
    /* ********************* Atributos ********************  */
    private int pa;
    private int pb;
    private int pm;
    private int pn;
    private int px;
    private double[]plist;
    /* ********************* METODOS  *********************  */
    /* ===================== constructores ================= */
    /* --------------------- sin atributos -------------------*/
    public CGeneradorCongruencial(){
        pa=3;
        pb=5;
        px=3;
        pm=7;
        pn=3;
        plist=new double[100];
    }
    /* --------------------- con atributos -------------------*/
    public CGeneradorCongruencial(int a,int b,int m,int x,int n,double[]list){
        pa=a;
        pb=b;
        px=x;
        pm=m;
        pn=n;
        plist=list;
    }
    /* --------------------- Modificadores ------------------- */
    /* ---------------------  Selectores   ------------------- */
    public int a(){
        return pa;
    }
    public int b(){
        return pb;
    }
    public int x(){
        return px;
    }
    public int m(){
        return pm;
    }
    public int n(){
        return pn;
    }
    public double[]list(){
        return plist;
    }
    /* ===================== Otros Metodos =================== */
    public void GeneradorC(){
        for( int i=0; i<pn; i++){
            int w=((pa*px)+pb)%pm;
            double u=(double)w/pm;
            //System.out.println("U :"+(i+1)+" : "+u);
            plist[i]=u;
            px=w;
        }
    }
}

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package generador_de_numeros_aleatorios;

/**
 *
 * @author wildr
 */
public class CGeneradorDesplazamiento {
    /* ********************* Atributos ********************  */
    private int aq;
    private int ah;
    private int ai;
    private int alongitud;
    private double[]alist;
    /* ********************* METODOS  *********************  */
    /* ===================== constructores ================= */
    /* --------------------- sin atributos -------------------*/
    public CGeneradorDesplazamiento(){
        aq=5;
        ah=3;
        ai=3;
        alongitud=4;
        alist=new double[100];
    }
    /* --------------------- con atributos -------------------*/
    public CGeneradorDesplazamiento(int q,int h,int i,int longitud,double[]list){
        aq=q;
        ah=h;
        ai=i;
        alongitud=longitud;
        alist=list;
    }
    /* --------------------- Modificadores ------------------- */
    /* ---------------------  Selectores   ------------------- */
    public int q(){
        return aq;
    }
    public int h(){
        return ah;
    }
    public int i(){
        return ai;
    }
    public int longitud(){
        return alongitud;
    }
    public double[]list(){
        return alist;
    }
    /* ===================== Otros Metodos =================== */
    /* ---------------------- potencia ------------------------*/
    public int potencia(int a,int n){
        if(n==0)
            return 1;
        else
            return a*potencia(a,n-1);
    }
    /* ---------------------- generador -----------------------*/
    public void Generador_de_Desplazamiento(){
        int n=aq;
        int l=alongitud;
        int []bit=new int[10000];
        // inicializamos los q-bits
        for(int k=0; k<aq; k++){
            bit[k]=1;
            //System.out.print(bit[k]);
        }
        // obtenemos los 10-q bits siguientes
        for(int w=0; w<10; w++){
            bit[n]=(bit[n-ah]+bit[n-aq])%2;
            //System.out.print(bit[n]);
            n++;            
        }
        System.out.println("");
        // generamos n numeros aleatorios
        // tener mucho cuidado con l y el numero 1
        int a=0;
        int b=l;// ele
        for(int m=0; m<ai; m++){
            int count=0;
            int aux=0;
            for(int j=b-1; j>=a; j--){// nuemro uno
                count+=(bit[j]*(int)Math.pow(2.00,aux));
                aux++;
                 //System.out.print((Math.pow(2.00,(double)aux))+" "+aux+"\n");
            }
            System.out.println(count);
            
            System.out.println((double)(count)/potencia(2,alongitud));
            alist[m]=(double)((count)/potencia(2, alongitud));
            a+=l;
            b+=l;
        }
        
    }
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package BTTH2;

import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;
/**
 *
 * @author admin
 */
public class HocSinh {
    private String mssv, hoten, quequan;
    private Date ngaysinh;
    private double toan, van, anh;
    private int cnt = 0;
    {
        cnt ++;
        mssv = String.format("HS-%04d", cnt);
    }
    
    public HocSinh(){}
    public HocSinh(String hoten, Date ngaysinh, String quequan, double toan, double van, double anh){
        this.hoten = hoten;
        this.quequan = quequan;
        this.ngaysinh = ngaysinh;
        this.toan = toan;
        this.van = van;
        this.anh = anh;
    }
    
    public String getHoten() {
        return hoten;
    }

    public void setHoten(String hoten) {
        this.hoten = hoten;
    }

    public String getQuequan() {
        return quequan;
    }

    public void setQuequan(String quequan) {
        this.quequan = quequan;
    }

    public Date getNgaysinh() {
        return ngaysinh;
    }

    public void setNgaysinh(Date ngaysinh) {
        this.ngaysinh = ngaysinh;
    }

    public double getToan() {
        return toan;
    }

    public void setToan(double toan) {
        this.toan = toan;
    }

    public double getVan() {
        return van;
    }

    public void setVan(double van) {
        this.van = van;
    }

    public double getAnh() {
        return anh;
    }

    public void setAnh(double anh) {
        this.anh = anh;
    }

    public String getMssv() {
        return mssv;
    }
    
    @Override
    public String toString(){
        SimpleDateFormat df = new SimpleDateFormat("dd/MM/yyyy");
        return String.format("mssv: %s \n ho ten: %s \n ngay sinh: %s \n que quan: %s \n diem Toan: %.2f, diem Van: %.2f, diem Anh: %.2f \n",
                this.mssv, this.hoten, df.format(this.ngaysinh), this.quequan, this.toan, this.van, this.anh);
    }
    
    public int tuoi(){
        Calendar ngayhientai = Calendar.getInstance();
        Calendar ns = Calendar.getInstance();
        ns.setTime(ngaysinh);
        return ngayhientai.get(Calendar.YEAR) - ns.get(Calendar.YEAR);
    }
    public double diemtb(){
        return (toan + van + anh) / 3;
    }
    public String xeploai(){
        if(this.diemtb() >= 8) return "Gioi";
        if(this.diemtb() <8 && this.diemtb() >=6.5) return "Kha";
        if(this.diemtb() <6.5 && this.diemtb() >= 5) return "trung binh";
        return "yeu";
    }
}

package com.snso.helloworld;

import android.util.Log;

public class GetCinfo {
	
	//native  ����Ҫ������   ����ķ���  ��C / c++ ʵ��
	public static native String getStr();
	
	public static native int getInt();
	
	
	public static native void LedCtrl(int ledNum, int status);
	public static native void PwmCtrl();
	
	public static native void callBack(CBackInterface inter);
	
	
	public CBackInterface cbackInterface;
	
	public void cback(CBackInterface inter, int key)
	{
		inter.showCBack(key);
		
	}
	
	public interface CBackInterface{
		public void showCBack(int key);
	}
	
	public void setCBackInterface(CBackInterface cbackInterface){
		Log.i("SNSO", "setCBackInterface");
		this.cbackInterface = cbackInterface;
		
		
		Log.i("SNSO", "" + cbackInterface);
	}


}

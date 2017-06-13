package com.snso.helloworld;

import com.snso.helloworld.GetCinfo.CBackInterface;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity implements CBackInterface{

	private TextView myview;
	private Button btn_on;
	private Button btn_off;
	private Button btn_key;
	private Button btn_pwm;
	private TextView show_key;
	
	private GetCinfo cinfo ;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		Init_View();

		Init_Event();

		
		cinfo = new GetCinfo();
		
		
		cinfo.setCBackInterface(this);

	}

	private void Init_View() {
		myview = (TextView) findViewById(R.id.showInfo);

		btn_on = (Button) findViewById(R.id.btn_on);
		btn_off = (Button) findViewById(R.id.btn_off);
		btn_pwm = (Button) findViewById(R.id.btn_pwm);
		btn_key = (Button) findViewById(R.id.btn_key);
		show_key = (TextView) findViewById(R.id.show_key);

		myview.setText(GetCinfo.getStr());

		myview.setText(myview.getText() + "---" + GetCinfo.getInt());

	}

	private void Init_Event() {
		btn_on.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				GetCinfo.LedCtrl(1, 0);
			}
		});

		btn_off.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				GetCinfo.LedCtrl(0, 0);
			}
		});

		btn_key.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				
				new Thread(new Runnable() {
					
					@Override
					public void run() {
						GetCinfo.callBack(MainActivity.this);
						
					}
				}).start();
				
			}
		});
		
		btn_pwm.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				GetCinfo.PwmCtrl();
			}
		});
		
		

	}

	// 只执行一次 类使用的时候执行一次
	static {
		// 加载库名称
		System.loadLibrary("HelloWorld");
	}

	@Override
	public void showCBack(int key) {
		show_key.setText("按键 :" + key);
	}

}

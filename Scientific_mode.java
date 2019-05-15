package com.example.sci_calci;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class Scientific_mode extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_scientific_mode);
    }

    public void basicCal (View view)
    {
        Intent intent2 = new Intent (this, MainActivity.class);
        startActivity(intent2);
    }
}

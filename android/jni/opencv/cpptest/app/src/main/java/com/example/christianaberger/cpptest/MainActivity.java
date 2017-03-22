package com.example.christianaberger.cpptest;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.File;
import java.io.IOException;

public class MainActivity extends AppCompatActivity {
    private final static String TAG = MainActivity.class.getSimpleName();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        AssetUtilities assetUtilities = new AssetUtilities(this);
        TextView tv = (TextView) findViewById(R.id.sample_text);
        ImageView originalImageView = (ImageView)findViewById(R.id.image);
        ImageView grayedView = (ImageView)findViewById(R.id.gray);
        AssetManager assetManager = getAssets();
        MushroomDetector mushRoom = new MushroomDetector();
        File[] files = fetchImages();
        for (File file: files) {
            Bitmap bitmap = BitmapFactory.decodeFile(file.getAbsolutePath());
            originalImageView.setImageBitmap(bitmap);
            Mushroom mushroom = new Mushroom();
            mushroom.color = new byte[] {(byte)0x01, (byte)0x02, (byte)0x03};
            mushroom.mushroomName = "a name";
            Mushroom[] templates = new Mushroom[] {mushroom};
            Mushroom[] mushrooms = mushRoom.computeSchwammerlType(templates, file.getAbsolutePath());
            for (Mushroom mr: mushrooms) {
                Log.d(TAG, "mshroom: " + mr);
            }
            bitmap = BitmapFactory.decodeFile(file.getAbsolutePath());
            grayedView.setImageBitmap(bitmap);
        }
    }
    private File[] fetchImages() {
        File cacheDir = getCacheDir();
        File destinationFolder = new File(cacheDir, "mushroomimages");
        AssetUtilities assetUtilities = new AssetUtilities(this);
        File[] files = new File[0];
        try {
            files = assetUtilities.copyAssetToCacheFolder("mushroomimages", destinationFolder);
        } catch (IOException e) {
            Log.e(TAG, "failed to fetch images from assets", e);
        }
        return files;
    }
}

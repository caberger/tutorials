/*
 * Copyright (c) 2017 Aberger Software GmbH. All Rights Reserved.
 *               http://www.aberger.at
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may
 * obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */
package com.example.mushroom.identifier;

import android.content.Context;
import android.content.res.AssetManager;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/**
    Utilitis for working with Assets
 */
public class AssetUtilities {
    private final Context context;
    public AssetUtilities(Context context) {
        this.context = context;
    }
    /** copy a file from the assets to the file system.
     * @param assetName the name of the asset to copy
     * @param folder the folder to copy the file to
     * @throws IOException
     */
    public File[] copyAssetToCacheFolder(String assetName, File folder) throws IOException {
        if (!folder.isDirectory()) {
            if (!folder.mkdirs()) {
                throw new IOException("failed to create folder " + folder);
            }
        }
        AssetManager assetManager = context.getAssets();
        String [] assets = assetManager.list("mushroomimages");
        File[] files = new File[assets.length];
        OutputStream out = null;
        InputStream in = null;
        int position = 0;
        for (String asset: assets) {
            File destinationFile = new File(folder, asset);
            try {
                out = new FileOutputStream(destinationFile);
                String name = assetName + "/" + asset;
                in = assetManager.open(name, AssetManager.ACCESS_STREAMING);
                copyFile(in, out);
                files[position++] = destinationFile;
            } catch(Exception e) {
                throw e;
            } finally {
                if (in != null) {
                    in.close();
                }
                if (out != null) {
                    out.close();
                }
            }
        }
        return files;
    }

    /** helper function to copy the contents of a stream to another stream
     *
     * @param in the input stream
     * @param out the output stream
     * @throws IOException
     */
    public void copyFile(InputStream in, OutputStream out) throws IOException {
        byte[] buffer = new byte[1024];
        int read = -1;
        while((read = in.read(buffer)) != -1){
            out.write(buffer, 0, read);
        }
        out.flush();
    }
}

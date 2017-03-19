opencv/c++ unter Android
===========================================

opencv aus dem Source Code in der Android Native Toolchain kompilieren
----------------------------------------------------------------------

1. Android Studo in in aktuellster Version installieren
2. in den "Android SDK Tools" CMake und NDK installieren
3. Python installieren
4. CMake installieren
5. [Android NDK standalone toolchain](https://developer.android.com/ndk/guides/standalone_toolchain.html) durchlesen und die Parameter in der Datei ```maketoolchain.cmd``` anpassen. 
6. OpenCV [Source Code](https://github.com/opencv/opencv/releases) downloaden und in ein Verzeichnis entpacken.
4. Die Datei ```scripts\env.cmd``` auf die Pfade am eigenen Rechner anpassen.
4. eine Shell öffnen durch das Doppelklicken der Datei ```shell.cmd``` im Unterverzeichnis ```scripts```, dorthin wechseln und dann von dieser Commandline aus maketoolchain.cmd ausführen, dies erstellt auf dem Desktop ein Toolchain -Verzeichnis ```ndk```
7. im immer noch offenen Command - Prompt eingeben: opencvbuild.cmd
13. dieses neu installierte install Verzeichnis enthält jetzt die include und library - Dateien für die in der Toolchain gewählte Architektur.


# WOFFLES

A bare-bones windows application that sets World of Final Fantasy (WOFF) into "fullscreen windowed" mode on the PC.

## What does it do?

It scans window classes looking for WOFF. Upon locating WOFF it strips the window chrome and sets it fullscreen, displays a dialog to let you know it is done, and then exits. It should only take a few seconds.

## How is this any different from the "official" fullscreen mode?

The official fullscreen mode is not a windowed mode, and you might notice you can't alt-tab out of it, can't winkey out of it, etc. It's quite annoying if your goal was to stream your session, or if you just like to be able to do other things while gaming.

## Disclaimer

You use this at your own risk. The author(s) accept no liability for your use, non-use or inability to use this software.

## Pre-Requisites

You may require a VC2017 x86 redist if you are using the official build (if you are building this yourself, you will already have all the deps you need, nothing third party is used.)

End-Users can download the vcredist from:

https://download.visualstudio.microsoft.com/download/pr/749aa419-f9e4-4578-a417-a43786af205e/d59197078cc425377be301faba7dd87a/vc_redist.x86.exe

You should only do this if you have problems running the app, as there may already be a (potentially newer) version of the redist installed by a game or somesuch.

## How-To

Do not trust executables from third parties, [an official build is available on github](https://github.com/wilson0x4d/woffles/releases).

NOTE: If you have WOFF configured to run using the official "fullscreen" mode, you will first want to reconfigure it to run in "windowed" mode. WOFFLES will *not* force WOFF into windowed mode for you.

1. Launch WOFF
2. Launch WOFFLES
3. Enjoy!

## Problems?

mailto:woffles@mrshaunwilson.com

## Donations?

If you found this useful, I find bitcoin useful:

15YCvZ8idVcTkfGdb5CyQMdRgREx5mgMSQ

Thanks!

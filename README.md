# laba-diena-tts

## about
TTS (Text To Speech) synthesis engine for Lithuanian language. The underlying core synhesizer is LIEPA speach synthesizer.

## dev environments
Source code is prepared for multiple development environments:
 - Visual Studio 2015: VS2015.sln
 - Android Studio project (applications/android/) for building android TTS engine service
 - VSCode workspace: vscode.code-workspace (gcc)

### additional dependencies
After compiling source code download archive from [HERE](https://www.xn--ratija-ckb.lt/liepa/infrastrukt%C5%ABrin%C4%97s-paslaugos/elektroninio-teksto-skaitytuvas/7563).
Inside you will find voice models (directories: Aiste, Regina, Edvardas, Vladas and files: abb.txt, inicialai1.txt, inicialai2.txt, rules.txt, skaitm.txt) which have to be copied next to compiled libraries.

## Google Play 
 - [labadienatts app](https://play.google.com/apps/testing/com.gscoder.android.labadienatts)

## Native modules
See [details](./native-modules)

## LIEPA

LIEPA project details: https://www.raštija.lt/liepa

Source code obtained from https://www.raštija.lt/liepa/infrastrukturines-paslaugos/elektroninio-teksto-skaitytuvas/7563

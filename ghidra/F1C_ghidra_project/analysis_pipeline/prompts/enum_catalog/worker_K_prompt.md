# WORKER K — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker K of 20, items 3311–3641.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_K.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

3311. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00402220__FUN_00402220.c
3312. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404850__FUN_00404850.c
3313. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405013__sub_405013.c
3314. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00405a30__sub_405A30.c
3315. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406700__FUN_00406700.c
3316. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407920__FUN_00407920.c
3317. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408280__FUN_00408280.c
3318. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409a00__sub_409A00.c
3319. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b5a0__FUN_0040b5a0.c
3320. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c780__FUN_0040c780.c
3321. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d3c0__FUN_0040d3c0.c
3322. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e1f0__FUN_0040e1f0.c
3323. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040f100__FUN_0040f100.c
3324. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410b60__FUN_00410b60.c
3325. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411bf0__FUN_00411bf0.c
3326. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00414210__FUN_00414210.c
3327. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00415550__FUN_00415550.c
3328. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004189b0__FUN_004189b0.c
3329. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004198b0__FUN_004198b0.c
3330. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041b3c0__FUN_0041b3c0.c
3331. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041f040__FUN_0041f040.c
3332. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421480__FUN_00421480.c
3333. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421ad0__FUN_00421ad0.c
3334. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00424060__FUN_00424060.c
3335. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00429470__FUN_00429470.c
3336. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042add0__FUN_0042add0.c
3337. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bda0__FUN_0042bda0.c
3338. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042e1f0__FUN_0042e1f0.c
3339. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00431390__FUN_00431390.c
3340. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004326e0__FUN_004326e0.c
3341. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00433370__FUN_00433370.c
3342. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434820__FUN_00434820.c
3343. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004363f0__FUN_004363f0.c
3344. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ba20__FUN_0043ba20.c
3345. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043ec50__FUN_0043ec50.c
3346. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004432f0__FUN_004432f0.c
3347. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447c70__FUN_00447c70.c
3348. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448e50__FUN_00448e50.c
3349. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449f60__FUN_00449f60.c
3350. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044bb60__FUN_0044bb60.c
3351. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c830__FUN_0044c830.c
3352. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb60__FUN_0044cb60.c
3353. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cdd0__FUN_0044cdd0.c
3354. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d054__sub_44D054.c
3355. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d3d0__FUN_0044d3d0.c
3356. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d790__FUN_0044d790.c
3357. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044db50__FUN_0044db50.c
3358. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044df10__FUN_0044df10.c
3359. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e2d0__FUN_0044e2d0.c
3360. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e690__FUN_0044e690.c
3361. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044ea50__FUN_0044ea50.c
3362. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f050__FUN_0044f050.c
3363. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044fbb0__FUN_0044fbb0.c
3364. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004533a0__FUN_004533a0.c
3365. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004560a0__FUN_004560a0.c
3366. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457cf0__thunk_FUN_00458020.c
3367. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459a40__FUN_00459a40.c
3368. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045ba60__FUN_0045ba60.c
3369. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bf60__FUN_0045bf60.c
3370. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045cbf0__FUN_0045cbf0.c
3371. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e5d0__FUN_0045e5d0.c
3372. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461480__FUN_00461480.c
3373. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462140__FUN_00462140.c
3374. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462a00__FUN_00462a00.c
3375. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463cd0__FUN_00463cd0.c
3376. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464a40__FUN_00464a40.c
3377. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465300__FUN_00465300.c
3378. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466300__FUN_00466300.c
3379. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00467dc0__FUN_00467dc0.c
3380. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a510__FUN_0046a510.c
3381. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c74c__sub_46C74C.c
3382. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046dd10__FUN_0046dd10.c
3383. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046fcf9__sub_46FCF9.c
3384. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470960__FUN_00470960.c
3385. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471dc0__FUN_00471dc0.c
3386. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00473b00__FUN_00473b00.c
3387. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474f40__FUN_00474f40.c
3388. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476100__sub_476100.c
3389. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477410__FUN_00477410.c
3390. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00478180__FUN_00478180.c
3391. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479690__FUN_00479690.c
3392. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00479bd0__FUN_00479bd0.c
3393. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a3a0__FUN_0047a3a0.c
3394. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b9c0__FUN_0047b9c0.c
3395. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c940__FUN_0047c940.c
3396. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f1f0__FUN_0047f1f0.c
3397. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004856f0__FUN_004856f0.c
3398. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486280__FUN_00486280.c
3399. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486710__FUN_00486710.c
3400. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487210__sub_487210.c
3401. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487960__FUN_00487960.c
3402. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488b00__FUN_00488b00.c
3403. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00489920__FUN_00489920.c
3404. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048a8d0__sub_48A8D0.c
3405. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048bc70__FUN_0048bc70.c
3406. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d230__FUN_0048d230.c
3407. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e0b0__FUN_0048e0b0.c
3408. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048ea60__FUN_0048ea60.c
3409. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fd80__FUN_0048fd80.c
3410. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490550__sub_490550.c
3411. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004915a0__FUN_004915a0.c
3412. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491db0__FUN_00491db0.c
3413. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494c20__FUN_00494c20.c
3414. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495190__FUN_00495190.c
3415. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495dc0__FUN_00495dc0.c
3416. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004974a0__FUN_004974a0.c
3417. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497e80__FUN_00497e80.c
3418. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004988c0__FUN_004988c0.c
3419. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499140__FUN_00499140.c
3420. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499850__FUN_00499850.c
3421. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499c50__FUN_00499c50.c
3422. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a110__FUN_0049a110.c
3423. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a5a0__FUN_0049a5a0.c
3424. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049afa0__FUN_0049afa0.c
3425. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ba30__FUN_0049ba30.c
3426. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d5d0__FUN_0049d5d0.c
3427. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e9a0__FUN_0049e9a0.c
3428. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049fdb0__FUN_0049fdb0.c
3429. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0d10__FUN_004a0d10.c
3430. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a19d0__sub_4A19D0.c
3431. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a2220__FUN_004a2220.c
3432. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a4030__FUN_004a4030.c
3433. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5750__FUN_004a5750.c
3434. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6e50__FUN_004a6e50.c
3435. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b0170__FUN_004b0170.c
3436. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1780__FUN_004b1780.c
3437. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1de0__FUN_004b1de0.c
3438. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2750__FUN_004b2750.c
3439. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b90__FUN_004b2b90.c
3440. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3d50__FUN_004b3d50.c
3441. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b4760__FUN_004b4760.c
3442. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5630__FUN_004b5630.c
3443. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b69f0__FUN_004b69f0.c
3444. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b86e0__FUN_004b86e0.c
3445. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9890__FUN_004b9890.c
3446. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9fb0__FUN_004b9fb0.c
3447. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bab20__FUN_004bab20.c
3448. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb6b0__FUN_004bb6b0.c
3449. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc340__FUN_004bc340.c
3450. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004be010__FUN_004be010.c
3451. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bfd40__FUN_004bfd40.c
3452. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c1390__FUN_004c1390.c
3453. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c28d0__FUN_004c28d0.c
3454. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2ff0__FUN_004c2ff0.c
3455. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4cf0__FUN_004c4cf0.c
3456. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6920__FUN_004c6920.c
3457. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7bf0__FUN_004c7bf0.c
3458. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8350__FUN_004c8350.c
3459. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8ee0__FUN_004c8ee0.c
3460. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c99d0__sub_4C99D0.c
3461. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cb4f0__FUN_004cb4f0.c
3462. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cd980__sub_4CD980.c
3463. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d0040__FUN_004d0040.c
3464. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1ad0__FUN_004d1ad0.c
3465. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d37b0__sub_4D37B0.c
3466. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5984__FUN_004d5984.c
3467. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7aa0__FUN_004d7aa0.c
3468. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d8130__FUN_004d8130.c
3469. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d9290__FUN_004d9290.c
3470. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004daea0__FUN_004daea0.c
3471. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dbb60__FUN_004dbb60.c
3472. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dca80__FUN_004dca80.c
3473. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd400__FUN_004dd400.c
3474. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004df0a0__FUN_004df0a0.c
3475. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e16f0__FUN_004e16f0.c
3476. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2ad0__FUN_004e2ad0.c
3477. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4910__FUN_004e4910.c
3478. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e8ce0__FUN_004e8ce0.c
3479. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ec080__FUN_004ec080.c
3480. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ef4f0__FUN_004ef4f0.c
3481. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f0dd0__FUN_004f0dd0.c
3482. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1c40__FUN_004f1c40.c
3483. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f6a50__FUN_004f6a50.c
3484. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8370__FUN_004f8370.c
3485. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8d40__FUN_004f8d40.c
3486. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9f70__FUN_004f9f70.c
3487. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc910__FUN_004fc910.c
3488. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff3a0__FUN_004ff3a0.c
3489. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050070d__FUN_0050070d.c
3490. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005029e5__FUN_005029e5.c
3491. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503ce3__FUN_00503ce3.c
3492. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00506538__FUN_00506538.c
3493. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00507cc6__FUN_00507cc6.c
3494. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509047__FUN_00509047.c
3495. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509f0c__sub_509F0C.c
3496. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a92d__FUN_0050a92d.c
3497. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b27c__FUN_0050b27c.c
3498. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b7fb__FUN_0050b7fb.c
3499. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2e3__FUN_0050c2e3.c
3500. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050cba3__FUN_0050cba3.c
3501. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d728__FUN_0050d728.c
3502. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050df88__FUN_0050df88.c
3503. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e585__sub_50E585.c
3504. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f904__FUN_0050f904.c
3505. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005110fc__FUN_005110fc.c
3506. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00511f70__FUN_00511f70.c
3507. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005126d9__FUN_005126d9.c
3508. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513d2f__FUN_00513d2f.c
3509. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00515927__FUN_00515927.c
3510. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051629f__FUN_0051629f.c
3511. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005170c0__FUN_005170c0.c
3512. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00518032__FUN_00518032.c
3513. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519bb2__FUN_00519bb2.c
3514. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051bad1__FUN_0051bad1.c
3515. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c6e1__FUN_0051c6e1.c
3516. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051dcaa__FUN_0051dcaa.c
3517. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051ec40__FUN_0051ec40.c
3518. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f98e__sub_51F98E.c
3519. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00520ce0__sub_520CE0.c
3520. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005229b5__sub_5229B5.c
3521. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00526550__FUN_00526550.c
3522. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005285a6__FUN_005285a6.c
3523. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052d8c0__thunk_FUN_0052d990.c
3524. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e1c0__thunk_FUN_0052d9b0.c
3525. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00531b50__FUN_00531b50.c
3526. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535560__FUN_00535560.c
3527. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00537000__FUN_00537000.c
3528. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00539670__FUN_00539670.c
3529. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053b0d0__FUN_0053b0d0.c
3530. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c102__sub_53C102.c
3531. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c900__FUN_0053c900.c
3532. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d400__FUN_0053d400.c
3533. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005400c0__FUN_005400c0.c
3534. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541420__FUN_00541420.c
3535. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542050__FUN_00542050.c
3536. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543250__FUN_00543250.c
3537. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00544c50__FUN_00544c50.c
3538. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005456b0__FUN_005456b0.c
3539. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546370__FUN_00546370.c
3540. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547400__FUN_00547400.c
3541. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548c20__FUN_00548c20.c
3542. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00549fb0__FUN_00549fb0.c
3543. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054b330__FUN_0054b330.c
3544. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bf10__FUN_0054bf10.c
3545. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054ca00__FUN_0054ca00.c
3546. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eaf0__FUN_0054eaf0.c
3547. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fc50__FUN_0054fc50.c
3548. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005505a0__FUN_005505a0.c
3549. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005514a0__FUN_005514a0.c
3550. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005527c0__FUN_005527c0.c
3551. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005539f0__FUN_005539f0.c
3552. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554700__FUN_00554700.c
3553. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005564b0__FUN_005564b0.c
3554. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556980__FUN_00556980.c
3555. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00557ce0__FUN_00557ce0.c
3556. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00559630__FUN_00559630.c
3557. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bd20__FUN_0055bd20.c
3558. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c7b0__FUN_0055c7b0.c
3559. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d320__FUN_0055d320.c
3560. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055f060__FUN_0055f060.c
3561. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560e50__FUN_00560e50.c
3562. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561d40__FUN_00561d40.c
3563. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562b50__FUN_00562b50.c
3564. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563df0__FUN_00563df0.c
3565. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005645b0__FUN_005645b0.c
3566. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00564990__FUN_00564990.c
3567. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565d50__FUN_00565d50.c
3568. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00566940__FUN_00566940.c
3569. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567120__FUN_00567120.c
3570. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567a90__FUN_00567a90.c
3571. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005685b0__FUN_005685b0.c
3572. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00569410__FUN_00569410.c
3573. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056baf0__FUN_0056baf0.c
3574. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056d880__FUN_0056d880.c
3575. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00578f76__FUN_00578f76.c
3576. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a270__FUN_0057a270.c
3577. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a810__FUN_0057a810.c
3578. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aa70__FUN_0057aa70.c
3579. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b230__sub_57B230.c
3580. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b950__FUN_0057b950.c
3581. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057db80__FUN_0057db80.c
3582. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ee80__FUN_0057ee80.c
3583. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581780__FUN_00581780.c
3584. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582310__FUN_00582310.c
3585. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005831b0__sub_5831B0.c
3586. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583a80__FUN_00583a80.c
3587. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585130__FUN_00585130.c
3588. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585d20__FUN_00585d20.c
3589. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586320__FUN_00586320.c
3590. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586de0__FUN_00586de0.c
3591. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587220__FUN_00587220.c
3592. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005876c0__FUN_005876c0.c
3593. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587bcf__FUN_00587bcf.c
3594. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005881f0__FUN_005881f0.c
3595. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058893a__FUN_0058893a.c
3596. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005897ca__FUN_005897ca.c
3597. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589d7d__FUN_00589d7d.c
3598. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a42f__FUN_0058a42f.c
3599. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058aa6f__FUN_0058aa6f.c
3600. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b5d4__FUN_0058b5d4.c
3601. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bfec__FUN_0058bfec.c
3602. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058ca19__FUN_0058ca19.c
3603. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dce5____fload_withFB.c
3604. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e4d2__FUN_0058e4d2.c
3605. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058fd90__FUN_0058fd90.c
3606. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059083b____ctrandisp1.c
3607. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591e49__FUN_00591e49.c
3608. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592f2c__FUN_00592f2c.c
3609. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593db8__FUN_00593db8.c
3610. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595135__FUN_00595135.c
3611. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005959a0__FUN_005959a0.c
3612. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005968f6__FUN_005968f6.c
3613. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059750a__FUN_0059750a.c
3614. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598600__FUN_00598600.c
3615. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005986a2__WSACleanup.c
3616. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987dc__sub_5987DC.c
3617. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598d6d__FUN_00598d6d.c
3618. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059942b__FUN_0059942b.c
3619. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005997cb__FUN_005997cb.c
3620. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599904__FUN_00599904.c
3621. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599ed6__FUN_00599ed6.c
3622. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a4c9__FUN_0059a4c9.c
3623. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a9c2__FUN_0059a9c2.c
3624. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059af17__FUN_0059af17.c
3625. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b760__FUN_0059b760.c
3626. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c127__FUN_0059c127.c
3627. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4e6__Unwind_0059c4e6.c
3628. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5f8__Unwind_0059c5f8.c
3629. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6c0__Unwind_0059c6c0.c
3630. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c812__Unwind_0059c812.c
3631. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c910__Unwind_0059c910.c
3632. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca80__Unwind_0059ca80.c
3633. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cbe8__Unwind_0059cbe8.c
3634. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd40__Unwind_0059cd40.c
3635. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cec9__Unwind_0059cec9.c
3636. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfda__Unwind_0059cfda.c
3637. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0e0__Unwind_0059d0e0.c
3638. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d26c__Unwind_0059d26c.c
3639. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d427__Unwind_0059d427.c
3640. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d594__Unwind_0059d594.c
3641. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059dad5__FUN_0059dad5.c

## TASK
For each .c file:
1. Find switch statements — extract case values and purposes
2. Find comparisons against literal integers (if x == 3, if x < 7, etc.)
3. Find assignments of literal values to globals/struct fields
4. Group related values into enum candidates

## OUTPUT FORMAT

```
=== ENUM DISCOVERIES ===

### EnumName (new or extension of existing)
Source evidence: FUN_XXXXXXXX, FUN_YYYYYYYY
Variable: DAT_XXXXXXXX or param_1+0xNNN

| Value | Meaning | Evidence | Confidence |
|-------|---------|----------|------------|

=== MAGIC NUMBERS ===
| Value | Hex | Type | Used In | Likely Meaning |
|-------|-----|------|---------|---------------|
| 0.017453 | — | float | FUN_X | DEG_TO_RAD |
```

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_K.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.

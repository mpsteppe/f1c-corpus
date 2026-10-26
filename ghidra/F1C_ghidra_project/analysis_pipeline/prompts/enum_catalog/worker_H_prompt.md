# WORKER H — F1C Magic Number / Enum Recovery

You are identifying hardcoded magic numbers and grouping them into enums.
Worker H of 20, items 2318–2648.

## STEP 1 — LOAD REFERENCES
`%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — known globals with value ranges

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_H.md

## KNOWN ENUMS — do NOT re-discover
- SessionType: 0-5=practice, 6=quali, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## YOUR FILES (331)

2318. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00401340__FUN_00401340.c
2319. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004047d0__FUN_004047d0.c
2320. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00404f10__FUN_00404f10.c
2321. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004058d0__FUN_004058d0.c
2322. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00406640__FUN_00406640.c
2323. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00407520__FUN_00407520.c
2324. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00408220__FUN_00408220.c
2325. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00409440__FUN_00409440.c
2326. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040b410__sub_40B410.c
2327. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040c610__FUN_0040c610.c
2328. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040d2d0__FUN_0040d2d0.c
2329. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040e1c0__FUN_0040e1c0.c
2330. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0040eec0__FUN_0040eec0.c
2331. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00410af0__FUN_00410af0.c
2332. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00411a50__FUN_00411a50.c
2333. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004141a0__FUN_004141a0.c
2334. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004150c0__FUN_004150c0.c
2335. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00418900__FUN_00418900.c
2336. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004193a0__FUN_004193a0.c
2337. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041b190__FUN_0041b190.c
2338. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0041ef00__FUN_0041ef00.c
2339. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004212e0__FUN_004212e0.c
2340. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00421a70__FUN_00421a70.c
2341. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00423e80__FUN_00423e80.c
2342. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00426cc0__FUN_00426cc0.c
2343. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042ad20__FUN_0042ad20.c
2344. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042bc40__FUN_0042bc40.c
2345. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0042dd80__FUN_0042dd80.c
2346. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00430600__FUN_00430600.c
2347. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004320a0__FUN_004320a0.c
2348. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004330d0__FUN_004330d0.c
2349. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00434450__thunk_FUN_00434860.c
2350. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004361d0__FUN_004361d0.c
2351. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004390a0__FUN_004390a0.c
2352. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0043eae0__FUN_0043eae0.c
2353. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004423b0__FUN_004423b0.c
2354. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00447ab0__FUN_00447ab0.c
2355. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00448da0__FUN_00448da0.c
2356. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00449a20__FUN_00449a20.c
2357. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044b370__FUN_0044b370.c
2358. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044c7a0__FUN_0044c7a0.c
2359. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cb00__FUN_0044cb00.c
2360. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cd70__FUN_0044cd70.c
2361. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044cff4__sub_44CFF4.c
2362. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d340__FUN_0044d340.c
2363. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044d700__FUN_0044d700.c
2364. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044dac0__FUN_0044dac0.c
2365. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044de80__FUN_0044de80.c
2366. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e240__FUN_0044e240.c
2367. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e600__FUN_0044e600.c
2368. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044e9c0__FUN_0044e9c0.c
2369. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044efc0__FUN_0044efc0.c
2370. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0044f7f0__FUN_0044f7f0.c
2371. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004531a0__FUN_004531a0.c
2372. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00456040__FUN_00456040.c
2373. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00457b00__FUN_00457b00.c
2374. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00459950__FUN_00459950.c
2375. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045b840__FUN_0045b840.c
2376. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045bed6__sub_45BED6.c
2377. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045c8b0__FUN_0045c8b0.c
2378. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0045e570__FUN_0045e570.c
2379. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004613e0__FUN_004613e0.c
2380. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00461f90__FUN_00461f90.c
2381. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00462850__FUN_00462850.c
2382. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00463c60__FUN_00463c60.c
2383. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00464990__FUN_00464990.c
2384. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00465160__FUN_00465160.c
2385. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00466290__FUN_00466290.c
2386. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004674e0__FUN_004674e0.c
2387. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046a270__FUN_0046a270.c
2388. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046c030__FUN_0046c030.c
2389. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046d6d0__FUN_0046d6d0.c
2390. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0046f4d0__FUN_0046f4d0.c
2391. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00470670__FUN_00470670.c
2392. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00471970__FUN_00471970.c
2393. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004734a0__FUN_004734a0.c
2394. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00474c50__FUN_00474c50.c
2395. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00476060__sub_476060.c
2396. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00477160__FUN_00477160.c
2397. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004780d0__FUN_004780d0.c
2398. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004793ec__sub_4793EC.c
2399. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004799e0__FUN_004799e0.c
2400. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047a230__FUN_0047a230.c
2401. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047b730__FUN_0047b730.c
2402. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047c7f0__FUN_0047c7f0.c
2403. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0047f080__FUN_0047f080.c
2404. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00485660__FUN_00485660.c
2405. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004861a0__FUN_004861a0.c
2406. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00486630__FUN_00486630.c
2407. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004871e0__sub_4871E0.c
2408. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00487760__FUN_00487760.c
2409. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00488970__FUN_00488970.c
2410. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004895b0__FUN_004895b0.c
2411. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048a3c0__FUN_0048a3c0.c
2412. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048b950__FUN_0048b950.c
2413. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048d0a0__FUN_0048d0a0.c
2414. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048df40__sub_48DF40.c
2415. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048e9e0__FUN_0048e9e0.c
2416. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0048fc80__FUN_0048fc80.c
2417. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00490390__FUN_00490390.c
2418. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491300__FUN_00491300.c
2419. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00491cf0__FUN_00491cf0.c
2420. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00494a70__FUN_00494a70.c
2421. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495120__FUN_00495120.c
2422. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00495b30__FUN_00495b30.c
2423. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497260__FUN_00497260.c
2424. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00497c40__FUN_00497c40.c
2425. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004987b0__FUN_004987b0.c
2426. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00498fb0__FUN_00498fb0.c
2427. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499680__sub_499680.c
2428. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499bb0__FUN_00499bb0.c
2429. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00499ee0__FUN_00499ee0.c
2430. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049a490__FUN_0049a490.c
2431. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049ae40__FUN_0049ae40.c
2432. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049b900__FUN_0049b900.c
2433. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049d440__FUN_0049d440.c
2434. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049e8e8__sub_49E8E8.c
2435. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0049f710__FUN_0049f710.c
2436. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a0c60__FUN_004a0c60.c
2437. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1367__FUN_004a1367.c
2438. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a1fb0__FUN_004a1fb0.c
2439. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a3b50__FUN_004a3b50.c
2440. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a5660__FUN_004a5660.c
2441. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004a6b80__FUN_004a6b80.c
2442. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ae9f0__FUN_004ae9f0.c
2443. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b15d0__FUN_004b15d0.c
2444. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b1c20__FUN_004b1c20.c
2445. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2580__FUN_004b2580.c
2446. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b2b40__FUN_004b2b40.c
2447. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b3c60__FUN_004b3c60.c
2448. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b45e0__FUN_004b45e0.c
2449. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b5460__FUN_004b5460.c
2450. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b6940__FUN_004b6940.c
2451. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b8480__FUN_004b8480.c
2452. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9860__FUN_004b9860.c
2453. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004b9e40__FUN_004b9e40.c
2454. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ba9f0__FUN_004ba9f0.c
2455. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bb4f0__FUN_004bb4f0.c
2456. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bc2f0__FUN_004bc2f0.c
2457. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bde20__FUN_004bde20.c
2458. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004bf730__FUN_004bf730.c
2459. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c11c0__FUN_004c11c0.c
2460. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2830__FUN_004c2830.c
2461. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c2fa0__FUN_004c2fa0.c
2462. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c4ba8__sub_4C4BA8.c
2463. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c6760__FUN_004c6760.c
2464. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c7b20__FUN_004c7b20.c
2465. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8210__FUN_004c8210.c
2466. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c8d90__FUN_004c8d90.c
2467. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004c9840__FUN_004c9840.c
2468. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ca430__FUN_004ca430.c
2469. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cd220__FUN_004cd220.c
2470. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004cf040__FUN_004cf040.c
2471. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d1670__FUN_004d1670.c
2472. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d2dd0__FUN_004d2dd0.c
2473. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d5885__sub_4D5885.c
2474. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7930__FUN_004d7930.c
2475. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d7fa0__FUN_004d7fa0.c
2476. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004d90d0__FUN_004d90d0.c
2477. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dad80__FUN_004dad80.c
2478. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dba00__FUN_004dba00.c
2479. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dc600__FUN_004dc600.c
2480. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dd010__FUN_004dd010.c
2481. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004dedb0__FUN_004dedb0.c
2482. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e0e70__FUN_004e0e70.c
2483. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e2760__FUN_004e2760.c
2484. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e4590__FUN_004e4590.c
2485. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004e87e0__FUN_004e87e0.c
2486. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ebc60__FUN_004ebc60.c
2487. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ee2d0__FUN_004ee2d0.c
2488. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f03e0__FUN_004f03e0.c
2489. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f1ba0__FUN_004f1ba0.c
2490. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f68b0__FUN_004f68b0.c
2491. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8250__FUN_004f8250.c
2492. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f8cf0__sub_4F8CF0.c
2493. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004f9f00__FUN_004f9f00.c
2494. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004fc850__FUN_004fc850.c
2495. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x004ff130__FUN_004ff130.c
2496. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00500680__FUN_00500680.c
2497. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00502102__sub_502102.c
2498. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00503920__FUN_00503920.c
2499. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005063a5__FUN_005063a5.c
2500. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005079a1__FUN_005079a1.c
2501. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00508d2d__FUN_00508d2d.c
2502. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00509d34__FUN_00509d34.c
2503. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050a8d9__FUN_0050a8d9.c
2504. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b228__FUN_0050b228.c
2505. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050b7af__FUN_0050b7af.c
2506. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c2a6__FUN_0050c2a6.c
2507. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050c9a9__FUN_0050c9a9.c
2508. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050d615__FUN_0050d615.c
2509. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050de26__thunk_FUN_0050de19.c
2510. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050e3e0__FUN_0050e3e0.c
2511. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0050f6f2__thunk_FUN_00516959.c
2512. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00510d60__FUN_00510d60.c
2513. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005118c1__FUN_005118c1.c
2514. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005124d5__FUN_005124d5.c
2515. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00513cd3__thunk_FUN_00517ec8.c
2516. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005158af__FUN_005158af.c
2517. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051613f__FUN_0051613f.c
2518. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00516f55__sub_516F55.c
2519. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00517f35__FUN_00517f35.c
2520. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00519986__FUN_00519986.c
2521. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051b45f__FUN_0051b45f.c
2522. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051c5a3__FUN_0051c5a3.c
2523. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051da17__FUN_0051da17.c
2524. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051eb5a__sub_51EB5A.c
2525. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0051f700__sub_51F700.c
2526. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052098e__sub_52098E.c
2527. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052278b__sub_52278B.c
2528. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00526321__sub_526321.c
2529. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052835f__FUN_0052835f.c
2530. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052b206__FUN_0052b206.c
2531. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0052e060__FUN_0052e060.c
2532. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00531250__FUN_00531250.c
2533. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00535390__FUN_00535390.c
2534. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00536e90__FUN_00536e90.c
2535. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00538ce0__sub_538CE0.c
2536. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053ae00__sub_53AE00.c
2537. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053bce0__FUN_0053bce0.c
2538. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053c6b0__FUN_0053c6b0.c
2539. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053d310__FUN_0053d310.c
2540. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0053fd40__FUN_0053fd40.c
2541. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005410f0__FUN_005410f0.c
2542. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00541d10__FUN_00541d10.c
2543. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00542950__FUN_00542950.c
2544. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00543bf0__FUN_00543bf0.c
2545. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005454d0__FUN_005454d0.c
2546. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00546230__FUN_00546230.c
2547. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00547390__FUN_00547390.c
2548. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00548a00__FUN_00548a00.c
2549. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005493b0__FUN_005493b0.c
2550. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054abe0__FUN_0054abe0.c
2551. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054bd30__FUN_0054bd30.c
2552. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054c300__FUN_0054c300.c
2553. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054eaa0__FUN_0054eaa0.c
2554. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0054fb90__FUN_0054fb90.c
2555. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00550310__FUN_00550310.c
2556. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551390__FUN_00551390.c
2557. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00551fb0__FUN_00551fb0.c
2558. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00553630__FUN_00553630.c
2559. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00554610__FUN_00554610.c
2560. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00556330__FUN_00556330.c
2561. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005568e0__FUN_005568e0.c
2562. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005574b0__FUN_005574b0.c
2563. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005593b0__FUN_005593b0.c
2564. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055bba0__FUN_0055bba0.c
2565. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055c440__FUN_0055c440.c
2566. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055d2a0__FUN_0055d2a0.c
2567. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0055eeaf__FUN_0055eeaf.c
2568. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00560ba0__FUN_00560ba0.c
2569. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00561acf__FUN_00561acf.c
2570. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00562830__FUN_00562830.c
2571. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00563a30__FUN_00563a30.c
2572. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005644f0__FUN_005644f0.c
2573. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005648d0__FUN_005648d0.c
2574. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00565520__FUN_00565520.c
2575. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005668b0__FUN_005668b0.c
2576. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00567010__FUN_00567010.c
2577. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005679c0__FUN_005679c0.c
2578. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005684a0__FUN_005684a0.c
2579. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005691d0__FUN_005691d0.c
2580. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056a840__FUN_0056a840.c
2581. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0056d3e0__FUN_0056d3e0.c
2582. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00575875__sub_575875.c
2583. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a200__FUN_0057a200.c
2584. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057a750__FUN_0057a750.c
2585. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057aa10__FUN_0057aa10.c
2586. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b050__FUN_0057b050.c
2587. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057b840__FUN_0057b840.c
2588. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057d660__FUN_0057d660.c
2589. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0057ead0__sub_57EAD0.c
2590. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00581600__sub_581600.c
2591. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00582190__FUN_00582190.c
2592. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583050__FUN_00583050.c
2593. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00583700__FUN_00583700.c
2594. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585020__FUN_00585020.c
2595. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00585bf0__FUN_00585bf0.c
2596. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586210__FUN_00586210.c
2597. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00586ca0__FUN_00586ca0.c
2598. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005871f0__FUN_005871f0.c
2599. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587620__FUN_00587620.c
2600. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00587b7f__FUN_00587b7f.c
2601. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00588156__sub_588156.c
2602. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005888a6____local_unwind2.c
2603. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589671__FUN_00589671.c
2604. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00589d62__ExitProcess.c
2605. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a380__FUN_0058a380.c
2606. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058a973__FUN_0058a973.c
2607. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058b465__FUN_0058b465.c
2608. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058bdcd__FUN_0058bdcd.c
2609. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058c7fc__FUN_0058c7fc.c
2610. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058dca0__FUN_0058dca0.c
2611. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058e290__FUN_0058e290.c
2612. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0058fc60__FUN_0058fc60.c
2613. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005906bb____ctrandisp2.c
2614. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00591d05__FUN_00591d05.c
2615. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00592bad__FUN_00592bad.c
2616. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00593c9c__FUN_00593c9c.c
2617. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00595058__FUN_00595058.c
2618. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005957bd__FUN_005957bd.c
2619. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00596840____allshl.c
2620. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00597359__FUN_00597359.c
2621. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005984aa__FUN_005984aa.c
2622. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598690____WSAFDIsSet.c
2623. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005987ad__sub_5987AD.c
2624. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00598cc1__FUN_00598cc1.c
2625. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599348__FUN_00599348.c
2626. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005997a1__FUN_005997a1.c
2627. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x005998cf__FUN_005998cf.c
2628. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x00599dd9__FUN_00599dd9.c
2629. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a43c__FUN_0059a43c.c
2630. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059a8fa__FUN_0059a8fa.c
2631. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ae61__FUN_0059ae61.c
2632. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059b5c0__FUN_0059b5c0.c
2633. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059bfb6__sub_59BFB6.c
2634. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c4b4__Unwind_0059c4b4.c
2635. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c5da__Unwind_0059c5da.c
2636. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c6a2__Unwind_0059c6a2.c
2637. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c7ee__Unwind_0059c7ee.c
2638. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059c8e6__Unwind_0059c8e6.c
2639. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059ca50__Unwind_0059ca50.c
2640. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cb9e__Unwind_0059cb9e.c
2641. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cd08__Unwind_0059cd08.c
2642. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cea2__Unwind_0059cea2.c
2643. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059cfb0__Unwind_0059cfb0.c
2644. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d0b2__Unwind_0059d0b2.c
2645. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d208__Unwind_0059d208.c
2646. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d3f0__Unwind_0059d3f0.c
2647. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059d558__Unwind_0059d558.c
2648. %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\0x0059da3a__FUN_0059da3a.c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\enum_catalog\worker_H.md.
1. Process ALL files in your list.
2. Do NOT re-report known enums unless you find NEW values for them.
3. Group physics constants: 9.81=gravity, 1.225=air density, 3.14159=PI.
4. Write to disk after every 20 files.

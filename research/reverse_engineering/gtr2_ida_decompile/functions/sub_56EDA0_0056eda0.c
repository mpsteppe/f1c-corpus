void __thiscall sub_56EDA0(float *this, float *a2, _DWORD *a3, float *a4, float *a5)
{
  unsigned int v5; // kr00_4
  int v6; // eax
  float *v8; // ebx
  float *v9; // eax
  float v10; // ecx
  double v11; // st7
  double v12; // st6
  float *v13; // eax
  float v14; // ecx
  float v15; // edx
  float v16; // eax
  float *v17; // eax
  float v18; // ecx
  float v19; // edx
  float *v20; // eax
  float v21; // ecx
  float v22; // edx
  float *v23; // eax
  float v24; // ecx
  float v25; // edx
  int *v26; // eax
  float v27; // ecx
  float v28; // edx
  int *v29; // eax
  int v30; // ecx
  float v31; // edx
  float v32; // eax
  float *v33; // eax
  float v34; // ecx
  float v35; // edx
  float v36; // eax
  float *v37; // eax
  float v38; // ecx
  float v39; // edx
  float v40; // eax
  float *v41; // eax
  float v42; // ecx
  float v43; // edx
  float v44; // eax
  float v45; // [esp+0h] [ebp-9Ch]
  float v46; // [esp+14h] [ebp-88h] BYREF
  float v47; // [esp+18h] [ebp-84h]
  float v48; // [esp+1Ch] [ebp-80h]
  float v49; // [esp+20h] [ebp-7Ch] BYREF
  float v50; // [esp+24h] [ebp-78h]
  float v51; // [esp+28h] [ebp-74h]
  int v52; // [esp+2Ch] [ebp-70h] BYREF
  float v53; // [esp+30h] [ebp-6Ch]
  float v54; // [esp+34h] [ebp-68h]
  float v55; // [esp+38h] [ebp-64h]
  float v56; // [esp+3Ch] [ebp-60h] BYREF
  float v57; // [esp+40h] [ebp-5Ch]
  float v58; // [esp+44h] [ebp-58h]
  float v59[3]; // [esp+48h] [ebp-54h] BYREF
  float v60[9]; // [esp+54h] [ebp-48h] BYREF
  float v61[9]; // [esp+78h] [ebp-24h] BYREF

  v8 = this + 9;
  sub_416420(this + 9, this + 3, this + 717, a2);
  *a3 = *((_DWORD *)this + 6);
  a3[1] = *((_DWORD *)this + 7);
  a3[2] = *((_DWORD *)this + 8);
  *a4 = flt_B70E88 * 0.01745433;
  *a5 = flt_B70EAC * 0.01745433;
  if ( !*(_DWORD *)(*(_DWORD *)this + 14820) && *((_DWORD *)this + 760) == 1 && !sub_4011C0(this + 735) )
  {
    v5 = __readeflags();
    v6 = *(_DWORD *)(dword_16C6CFC ^ loc_4B8116);
    __writeeflags(v5);
    if ( v6 )
    {
      v49 = this[711] + this[708];
      v50 = this[712] + this[709];
      v51 = this[713] + this[710];
      v9 = sub_401290(this + 720, &v49, &v46);
      v10 = v9[1];
      v49 = *v9;
      v51 = v9[2];
      v11 = v51 * this[737];
      v50 = v10;
      v12 = v10 * this[736];
      v45 = v11 + v12 + v49 * this[735] + v11 + v12 + v49 * this[735];
      v13 = sub_4012D0(this + 735, (float *)&v52, v45);
      v14 = *v13;
      v15 = v13[1];
      v16 = v13[2];
      v46 = v14;
      v47 = v15;
      v48 = v16;
      v17 = sub_401290(&v49, &v46, v59);
      v18 = v17[1];
      v56 = *v17;
      v19 = v17[2];
      v57 = v18;
      v58 = v19;
      v20 = sub_401290(this + 720, &v56, v59);
      v21 = *v20;
      v22 = v20[1];
      v51 = v20[2];
      v49 = v21;
      v50 = v22;
      if ( (byte_B70F30 & 1) != 0 )
        sub_416420(v8, this + 3, &v49, a2);
      if ( (byte_B70F30 & 2) != 0 )
      {
        v55 = sub_401220(&v56);
        if ( v55 != 0.0 )
        {
          sub_4163F0(&v56, v55);
          *(float *)&v52 = 0.0;
          v53 = 1.0;
          v54 = 0.0;
          v23 = sub_401320((float *)&v52, &v56, v59);
          v24 = v23[1];
          v46 = *v23;
          v25 = v23[2];
          v47 = v24;
          v48 = v25;
          v55 = sub_401220(&v46);
          if ( v55 != 0.0 )
          {
            sub_4163F0(&v46, v55);
            v26 = (int *)sub_401320(&v56, &v46, v59);
            v27 = *((float *)v26 + 1);
            v52 = *v26;
            v28 = *((float *)v26 + 2);
            v53 = v27;
            v60[0] = v46;
            v54 = v28;
            LODWORD(v60[1]) = v52;
            v60[3] = v47;
            v60[2] = v56;
            v60[4] = v27;
            v60[6] = v48;
            v60[5] = v57;
            v60[7] = v28;
            v60[8] = v58;
            sub_568FD0(v61, v8, v60);
            sub_40D5D0(v61, (int)a3);
            v29 = (int *)sub_401290(this + 723, &v49, v59);
            v30 = *v29;
            v31 = *((float *)v29 + 1);
            v32 = *((float *)v29 + 2);
            v52 = v30;
            v53 = v31;
            v54 = v32;
            sub_409390((float *)&v52);
            v33 = sub_401290(this + 726, &v49, v59);
            v34 = *v33;
            v35 = v33[1];
            v36 = v33[2];
            v46 = v34;
            v47 = v35;
            v48 = v36;
            sub_409390(&v46);
            *a4 = acos(v48 * v54 + v47 * v53 + v46 * *(float *)&v52);
            v37 = sub_401290(this + 729, &v49, v59);
            v38 = *v37;
            v39 = v37[1];
            v40 = v37[2];
            v46 = v38;
            v47 = v39;
            v48 = v40;
            sub_409390(&v46);
            v41 = sub_401290(this + 732, &v49, v59);
            v42 = *v41;
            v43 = v41[1];
            v44 = v41[2];
            v49 = v42;
            v50 = v43;
            v51 = v44;
            sub_409390(&v49);
            *a5 = acos(v51 * v48 + v50 * v47 + v49 * v46);
          }
        }
      }
    }
  }
}

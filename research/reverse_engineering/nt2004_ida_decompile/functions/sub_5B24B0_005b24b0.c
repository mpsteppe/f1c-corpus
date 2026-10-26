int __thiscall sub_5B24B0(void *this, int a2, _DWORD *a3)
{
  int v3; // ebp
  int v4; // esi
  int v6; // esi
  int v7; // [esp+10h] [ebp-C4h] BYREF
  int v8; // [esp+14h] [ebp-C0h]
  int v9; // [esp+18h] [ebp-BCh] BYREF
  int v10; // [esp+1Ch] [ebp-B8h] BYREF
  int v11; // [esp+20h] [ebp-B4h]
  int v12; // [esp+24h] [ebp-B0h] BYREF
  int v13; // [esp+28h] [ebp-ACh]
  int v14; // [esp+2Ch] [ebp-A8h] BYREF
  int v15; // [esp+30h] [ebp-A4h] BYREF
  int v16; // [esp+34h] [ebp-A0h] BYREF
  int v17; // [esp+38h] [ebp-9Ch] BYREF
  int v18; // [esp+3Ch] [ebp-98h] BYREF
  int v19; // [esp+40h] [ebp-94h] BYREF
  int v20; // [esp+44h] [ebp-90h] BYREF
  float v21; // [esp+48h] [ebp-8Ch] BYREF
  int v22; // [esp+4Ch] [ebp-88h]
  char v23[16]; // [esp+50h] [ebp-84h] BYREF
  char String[16]; // [esp+60h] [ebp-74h] BYREF
  int v25; // [esp+70h] [ebp-64h] BYREF
  int v26; // [esp+74h] [ebp-60h] BYREF
  int v27; // [esp+78h] [ebp-5Ch] BYREF
  int v28; // [esp+7Ch] [ebp-58h] BYREF
  int v29; // [esp+80h] [ebp-54h] BYREF
  int v30; // [esp+84h] [ebp-50h] BYREF
  int v31; // [esp+88h] [ebp-4Ch] BYREF
  int v32; // [esp+8Ch] [ebp-48h] BYREF
  int v33; // [esp+90h] [ebp-44h] BYREF
  int v34; // [esp+94h] [ebp-40h] BYREF
  int v35; // [esp+98h] [ebp-3Ch] BYREF
  int v36; // [esp+9Ch] [ebp-38h] BYREF
  int v37; // [esp+A0h] [ebp-34h] BYREF
  int v38; // [esp+A4h] [ebp-30h] BYREF
  int v39; // [esp+A8h] [ebp-2Ch] BYREF
  int v40; // [esp+ACh] [ebp-28h] BYREF
  int v41; // [esp+B0h] [ebp-24h] BYREF
  int v42; // [esp+B4h] [ebp-20h] BYREF
  int v43; // [esp+B8h] [ebp-1Ch] BYREF
  int v44; // [esp+BCh] [ebp-18h] BYREF
  int v45; // [esp+C0h] [ebp-14h] BYREF
  int v46; // [esp+C4h] [ebp-10h] BYREF
  int v47; // [esp+C8h] [ebp-Ch] BYREF
  int v48; // [esp+CCh] [ebp-8h] BYREF
  int v49; // [esp+D0h] [ebp-4h] BYREF

  v22 = (int)this;
  v3 = 0;
  v8 = 0;
  v13 = 1;
  v11 = 0;
  v19 = 0;
  v14 = 0;
  v21 = 0.0;
  v12 = 0;
  v9 = 0;
  v10 = 0;
  v15 = 0;
  v18 = 0;
  v17 = 0;
  v20 = 1120403456;
  v16 = 1065353216;
  while ( sub_5B1A10(a3) != 1 )
  {
    if ( *a3 == 3 )
      break;
    if ( *a3 != 2 )
    {
      sub_5B1DC0((int)a3, aType, String, 0);
      sub_5B1F50((int)a3, off_6110A4, (float *)&v10, (float *)&v9, (float *)&v12, 0);
      sub_5B1F50((int)a3, off_61BD64, &v21, (float *)&v14, (float *)&v19, 0);
      sub_5B1EA0((int)a3, EndPtr, &v17, &v18, &v15, 0);
      sub_5B1F50((int)a3, aRange, (float *)&v49, (float *)&v20, 0, 0);
      sub_5B1F50((int)a3, aIntensity, (float *)&v16, 0, 0, 0);
      if ( sub_5B1DC0((int)a3, aActive, v23, 0) )
      {
        if ( !strcmp(v23, aTrue) )
        {
          v13 = 1;
        }
        else if ( !strcmp(v23, aFalse) )
        {
          v13 = 0;
        }
      }
      if ( sub_5B1DC0((int)a3, aCastshadow, v23, 0) )
      {
        if ( !strcmp(v23, aTrue) )
        {
          v11 = 1;
        }
        else if ( !strcmp(v23, aFalse) )
        {
          v11 = 0;
        }
      }
      sub_5B1F50((int)a3, aPlane0, (float *)&v25, (float *)&v26, (float *)&v27, (float *)&v28);
      sub_5B1F50((int)a3, aPlane1, (float *)&v29, (float *)&v30, (float *)&v31, (float *)&v32);
      sub_5B1F50((int)a3, aPlane2, (float *)&v33, (float *)&v34, (float *)&v35, (float *)&v36);
      sub_5B1F50((int)a3, aPlane3, (float *)&v37, (float *)&v38, (float *)&v39, (float *)&v40);
      sub_5B1F50((int)a3, aPlane4, (float *)&v41, (float *)&v42, (float *)&v43, (float *)&v44);
      sub_5B1F50((int)a3, aPlane5, (float *)&v45, (float *)&v46, (float *)&v47, (float *)&v48);
      v3 = v17;
    }
  }
  if ( !strcmp(String, aDirectional) )
  {
    v8 = 1;
  }
  else if ( !strcmp(String, aStaticomni) )
  {
    v8 = 4;
  }
  else if ( !strcmp(String, aMovingomni) )
  {
    v8 = 2;
  }
  else if ( !strcmp(String, aVolume) )
  {
    v8 = 8;
  }
  v4 = v8;
  if ( sub_597680((void *)v22, &v7, a2, v8) )
    return -1;
  switch ( v4 )
  {
    case 1:
      sub_5B5AD0(v21, v14, v19);
      sub_5B5BE0(1);
      break;
    case 2:
    case 4:
      sub_5B5B50(v10, v9, v12);
      sub_5B5B80(v20);
      break;
    case 8:
      sub_5B5B50(v10, v9, v12);
      sub_5B5BE0(v11);
      sub_5B5BA0(0, &v25);
      sub_5B5BA0(1, &v29);
      sub_5B5BA0(2, &v33);
      sub_5B5BA0(3, &v37);
      sub_5B5BA0(4, &v41);
      sub_5B5BA0(5, &v45);
      break;
    default:
      break;
  }
  sub_5B5A70(2, v15 | ((v18 | (v3 << 8)) << 8));
  v6 = v16;
  sub_5B5A90(1, v16);
  sub_5B5A90(2, v6);
  sub_5B5A90(3, v6);
  sub_5B5990(v13);
  return 0;
}

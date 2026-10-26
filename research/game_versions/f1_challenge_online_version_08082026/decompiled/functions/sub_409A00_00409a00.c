int __thiscall sub_409A00(void *this)
{
  int result; // eax
  int v3; // esi
  int v4; // edx
  int v5; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  double v10; // st7
  int v11; // edx
  int v12; // ebx
  int v13; // [esp+14h] [ebp-98h]
  int v14; // [esp+18h] [ebp-94h]
  float v15; // [esp+1Ch] [ebp-90h]
  float v16; // [esp+20h] [ebp-8Ch]
  int v17; // [esp+20h] [ebp-8Ch]
  int v18; // [esp+20h] [ebp-8Ch]
  float v19; // [esp+24h] [ebp-88h]
  int v20; // [esp+24h] [ebp-88h]
  float v21; // [esp+24h] [ebp-88h]
  int v22; // [esp+28h] [ebp-84h]
  int v23; // [esp+38h] [ebp-74h]
  float v24; // [esp+3Ch] [ebp-70h] BYREF
  float v25; // [esp+40h] [ebp-6Ch] BYREF
  int v26; // [esp+44h] [ebp-68h] BYREF
  int v27; // [esp+48h] [ebp-64h] BYREF
  int v28; // [esp+4Ch] [ebp-60h] BYREF
  float v29; // [esp+50h] [ebp-5Ch]
  float v30; // [esp+54h] [ebp-58h]
  int v31; // [esp+58h] [ebp-54h] BYREF
  int v32; // [esp+5Ch] [ebp-50h]
  float v33; // [esp+60h] [ebp-4Ch]
  float v34; // [esp+64h] [ebp-48h] BYREF
  float v35; // [esp+68h] [ebp-44h]
  float v36; // [esp+6Ch] [ebp-40h]
  _DWORD v37[3]; // [esp+70h] [ebp-3Ch] BYREF
  float v38[3]; // [esp+7Ch] [ebp-30h] BYREF
  _BYTE v39[36]; // [esp+88h] [ebp-24h] BYREF

  result = *((_DWORD *)this + 1);
  v23 = result;
  if ( !result )
    return result;
  sub_54A160(4096);
  v3 = 0;
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 20))(this);
  switch ( *((_DWORD *)this + 13) )
  {
    case 0:
      sub_4E1FD0(&v31, &v28);
      v3 = *((_DWORD *)this + 4);
      sub_4D8860(1);
      goto LABEL_25;
    case 1:
      sub_4E2070(&v31, &v28);
      v3 = *((_DWORD *)this + 5);
      if ( byte_7CFE70 )
        sub_4D8860(1);
      goto LABEL_25;
    case 2:
      sub_4E1FD0(&v31, &v28);
      v3 = *((_DWORD *)this + 6);
      sub_4D8860(1);
      goto LABEL_25;
    case 3:
      sub_4E1FD0(&v31, &v28);
      v3 = *((_DWORD *)this + 7);
      sub_4D8860(1);
      v34 = *(float *)(v3 + 160);
      v4 = *(_DWORD *)(v3 + 164);
      v5 = *(_DWORD *)(v3 + 168);
      if ( v34 >= -2.95 )
      {
        if ( v34 <= -0.050000001 )
          goto LABEL_25;
        v34 = -0.050000001;
      }
      else
      {
        v34 = -2.95;
      }
      *(float *)(v3 + 160) = v34;
      *(_DWORD *)(v3 + 164) = v4;
      v6 = *(_DWORD *)v3;
      *(_DWORD *)(v3 + 168) = v5;
      (*(void (__thiscall **)(int))(v6 + 28))(v3);
LABEL_25:
      result = *(_DWORD *)(dword_7C54E0 + 88);
      v37[0] = result;
      v37[1] = *(_DWORD *)(dword_7C54E0 + 92);
      v37[2] = *(_DWORD *)(dword_7C54E0 + 96);
      if ( v3 )
      {
        if ( *((_DWORD *)this + 16) )
        {
          *(float *)&v28 = -*(float *)&v28;
          v29 = v29 + 3.1415927;
          v30 = -v30;
        }
        if ( *((float *)this + 18) != 0.0 || *((float *)this + 17) != 0.0 || *((float *)this + 19) != 0.0 )
        {
          sub_566E40(&v28, v39);
          if ( *((float *)this + 18) != 0.0 )
            sub_567400(*((float *)this + 18), (int)&v28);
          if ( *((float *)this + 17) != 0.0 )
            sub_567340(*((float *)this + 17), (int)&v28);
          if ( *((float *)this + 19) != 0.0 )
            sub_5674C0(*((float *)this + 19), (int)&v28);
        }
        v12 = *(_DWORD *)v3;
        v19 = sub_40C780(this);
        v16 = sub_4084A0();
        (*(void (__thiscall **)(int, int *, int *, _DWORD *, _DWORD, _DWORD))(v12 + 24))(
          v3,
          &v31,
          &v28,
          v37,
          LODWORD(v16),
          LODWORD(v19));
        v31 = *(_DWORD *)(v3 + 12);
        v32 = *(_DWORD *)(v3 + 16);
        v33 = *(float *)(v3 + 20);
        v28 = *(int *)(v3 + 24);
        v29 = *(float *)(v3 + 28);
        v30 = *(float *)(v3 + 32);
        sub_541CD0(v31, v32, v33, v28, SLODWORD(v29), SLODWORD(v30));
        if ( *(_DWORD *)(v23 + 432) )
        {
          sub_4E2130(v38, &v34);
          *(float *)&v22 = -v36;
          *(float *)&v20 = -v35;
          *(float *)&v17 = -v34;
          v15 = -v38[2];
          *(float *)&v14 = -v38[1];
          *(float *)&v13 = -v38[0];
          sub_541CD0(v13, v14, v15, v17, v20, v22);
        }
        sub_456060(&v25, &v24);
        sub_456080(&v27, &v26);
        v21 = v24 * 0.01745433;
        *(float *)&v18 = v25 * 0.01745433;
        sub_542050(v18, v21, 0);
        sub_5423C0(v27, v26);
        return sub_542680(*(float *)(v3 + 72));
      }
      return result;
    case 4:
      sub_4E1FD0(&v31, &v28);
      v3 = *((_DWORD *)this + 8) + 200 * *((_DWORD *)this + 15);
      goto LABEL_25;
    case 5:
      sub_4E1FD0(&v31, &v28);
      v3 = *((_DWORD *)this + 9);
      goto LABEL_25;
    case 6:
      sub_4E1FD0(&v31, &v28);
      v3 = *((_DWORD *)this + 10);
      goto LABEL_25;
    case 7:
      sub_4E1FD0(&v31, &v28);
      v3 = *((_DWORD *)this + 11);
      if ( dword_5BE900 )
      {
        if ( dword_5BE900 == 1 )
        {
          v7 = v3 + 188;
          v8 = v3 + 188;
          v9 = *(_DWORD *)(v3 + 188);
          v35 = *(float *)(v3 + 192);
          v10 = flt_5BE8FC + v35;
          goto LABEL_23;
        }
      }
      else
      {
        dword_5BE900 = 1;
      }
      goto LABEL_25;
    case 8:
      sub_4E1FD0(&v31, &v28);
      v3 = *((_DWORD *)this + 12);
      if ( dword_5BE900 )
      {
        if ( dword_5BE900 == 1 )
        {
          v7 = v3 + 188;
          v8 = v3 + 188;
          v9 = *(_DWORD *)(v3 + 188);
          v35 = *(float *)(v3 + 192);
          v10 = v35 - flt_5BE8FC;
LABEL_23:
          v11 = *(_DWORD *)(v8 + 8);
          v35 = v10;
          *(_DWORD *)v7 = v9;
          *(float *)(v7 + 4) = v35;
          *(_DWORD *)(v7 + 8) = v11;
          dword_5BE900 = 2;
        }
      }
      else
      {
        dword_5BE900 = 1;
      }
      goto LABEL_25;
    default:
      v31 = 0;
      v32 = 0;
      v33 = 0.0;
      *(float *)&v28 = 0.0;
      v29 = 0.0;
      v30 = 0.0;
      goto LABEL_25;
  }
}

int __thiscall sub_5DF7B0(char *this, char *ArgList, int a3, int *a4)
{
  char *v4; // edi
  int v7; // ebp
  char *v8; // eax
  float v9; // edx
  float v10; // [esp+2Ch] [ebp-290h]
  float v11; // [esp+30h] [ebp-28Ch]
  int v12; // [esp+34h] [ebp-288h]
  float v13; // [esp+38h] [ebp-284h]
  char v14; // [esp+48h] [ebp-274h]
  int v15; // [esp+50h] [ebp-26Ch] BYREF
  float v16; // [esp+54h] [ebp-268h]
  float v17; // [esp+58h] [ebp-264h]
  float v18; // [esp+5Ch] [ebp-260h]
  float v19; // [esp+60h] [ebp-25Ch]
  char *v20[3]; // [esp+64h] [ebp-258h] BYREF
  char *v21; // [esp+70h] [ebp-24Ch] BYREF
  char *EndPtr[2]; // [esp+74h] [ebp-248h] BYREF
  char *v23; // [esp+7Ch] [ebp-240h] BYREF
  char *v24; // [esp+80h] [ebp-23Ch] BYREF
  char *v25; // [esp+84h] [ebp-238h] BYREF
  char *v26; // [esp+88h] [ebp-234h] BYREF
  float v27; // [esp+8Ch] [ebp-230h]
  float v28; // [esp+90h] [ebp-22Ch]
  int v29; // [esp+94h] [ebp-228h]
  float v30; // [esp+98h] [ebp-224h]
  float v31; // [esp+9Ch] [ebp-220h]
  int v32; // [esp+A0h] [ebp-21Ch]
  float v33; // [esp+A4h] [ebp-218h]
  int v34; // [esp+A8h] [ebp-214h]
  float v35; // [esp+ACh] [ebp-210h]
  float v36; // [esp+B0h] [ebp-20Ch]
  float v37; // [esp+B4h] [ebp-208h]
  float v38; // [esp+B8h] [ebp-204h]
  char String[4]; // [esp+BCh] [ebp-200h] BYREF
  float v40; // [esp+C0h] [ebp-1FCh]
  char v41[256]; // [esp+1BCh] [ebp-100h] BYREF

  v4 = ArgList;
  v26 = this;
  if ( sub_5E59F0(&v15, ArgList, 0) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating view from scene file", v14);
    return -1;
  }
  else
  {
    *(_DWORD *)(v15 + 764) = this;
    v7 = 72;
    v34 = 0;
    v31 = 0.0;
    v33 = 0.0;
    v30 = 0.0;
    v27 = 0.0;
    v28 = 0.0;
    *(float *)&v21 = 0.0;
    v19 = 0.0;
    v16 = 0.0;
    v17 = 0.0;
    v29 = 72;
    v32 = 72;
    v20[0] = (char *)1120;
    if ( sub_5DF750(a4) != 1 )
    {
      while ( *a4 != 3 )
      {
        if ( *a4 != 2 )
        {
          if ( sub_5DF240((int)a4, "VIEW", v4, 0, 0, 0, 0, 0, 0, 0) && sub_5DF7B0((char)v4, v15, (int)a4) )
            return -1;
          if ( sub_5DEF70() )
          {
            v23 = (char *)(a4[515] + 1);
            v30 = strtod(v23, &v23);
            *(float *)&v29 = strtod(v23 + 1, &v23);
            *(float *)&v32 = strtod(v23 + 1, &v23);
          }
          if ( sub_5DEF70() )
          {
            v24 = (char *)(a4[515] + 1);
            *(float *)String = strtod(v24, &v24);
            v37 = strtod(v24 + 1, &v24);
          }
          if ( sub_5DEF70() )
          {
            EndPtr[0] = (char *)(a4[515] + 1);
            v7 = strtol(EndPtr[0], EndPtr, 10);
            v34 = strtol(EndPtr[0] + 1, EndPtr, 10);
            LODWORD(v31) = strtol(EndPtr[0] + 1, EndPtr, 10);
          }
          if ( sub_5DEF70() )
          {
            v26 = (char *)(a4[515] + 1);
            v38 = strtod(v26, &v26);
            v40 = strtod(v26 + 1, &v26);
          }
          if ( sub_5DEF70() )
          {
            v21 = (char *)(a4[515] + 1);
            v35 = strtod(v21, &v21);
            v33 = strtod(v21 + 1, &v21);
            v36 = strtod(v21 + 1, &v21);
          }
          if ( sub_5DEF70() )
          {
            v20[0] = (char *)(a4[515] + 1);
            strtod(v20[0], v20);
            strtod(v20[0] + 1, v20);
            strtod(v20[0] + 1, v20);
          }
          if ( sub_5DEF70() )
          {
            v24 = (char *)(a4[515] + 1);
            v18 = strtod(v24, &v24);
            v17 = strtod(v24 + 1, &v24);
            if ( v18 <= 1.0 )
              v18 = (double)*(int *)(dword_FB27A4 + 9408) * v18;
            if ( v17 <= 1.0 )
              v17 = (double)*(int *)(dword_FB27A4 + 9412) * v17;
          }
          if ( sub_5DEF70() )
          {
            v25 = (char *)(a4[515] + 1);
            v19 = strtod(v25, &v25);
            *(float *)&v21 = strtod(v25 + 1, &v25);
            if ( v19 <= 1.0 )
              v19 = (double)*(int *)(dword_FB27A4 + 9408) * v19;
            if ( *(float *)&v21 <= 1.0 )
              *(float *)&v21 = (double)*(int *)(dword_FB27A4 + 9412) * *(float *)&v21;
          }
          if ( sub_5DF240((int)a4, "CLEAR", String, 0, 0, 0, 0, 0, 0, 0) )
          {
            if ( !strcmp(String, "TRUE") )
              v8 = (char *)((int)v20[0] | 2);
            else
              v8 = (char *)((int)v20[0] & 0xFFFFFFFD);
            v20[0] = v8;
          }
          sub_5DF240((int)a4, "BGMAP", v41, 0, 0, 0, 0, 0, 0, 0);
          sub_5DF240((int)a4, "SEPARATESURFACE", String, 0, 0, 0, 0, 0, 0, 0);
          v4 = ArgList;
        }
        if ( sub_5DF750(a4) == 1 )
          break;
      }
    }
    sub_5E53C0(0);
    v11 = *(float *)&v21 - v16 * 0.5;
    v10 = v19 - v17 * 0.5;
    sub_5E53E0(v10, v11, v17, v16, 0);
    v13 = v35 * 0.01745433;
    *(float *)&v12 = v37 * 0.01745433;
    sub_5E5240(v12, v13, 0);
    sub_5E54E0(LODWORD(v36), LODWORD(v38));
    sub_4CD350((_DWORD *)v15, v29 + ((v32 + (v7 << 8)) << 8));
    v9 = *(float *)&v34;
    *(char **)v15 = v20[0];
    sub_5E51D0(v28, v27, v30, v33, v31, v9);
    if ( a3 )
      sub_5E59A0(v15);
    return 0;
  }
}

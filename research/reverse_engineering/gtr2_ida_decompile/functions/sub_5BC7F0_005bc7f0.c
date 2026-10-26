void __thiscall sub_5BC7F0(char *this, int a2, int a3, int a4)
{
  float *v5; // esi
  int v6; // ebx
  int i; // edi
  float *v8; // eax
  int v9; // ecx
  float v10; // edx
  float v11; // eax
  int v12; // edx
  int v13; // ebx
  int v14; // edi
  int v15; // edx
  float *v16; // edi
  double v17; // st7
  double v18; // st6
  double v19; // st7
  char *v20; // [esp-8h] [ebp-28h]
  int v21; // [esp+10h] [ebp-10h]
  int v22; // [esp+14h] [ebp-Ch] BYREF
  float v23; // [esp+18h] [ebp-8h]
  float v24; // [esp+1Ch] [ebp-4h]

  v5 = (float *)(this + 480);
  *((_DWORD *)this + 120) = 2139095039;
  *((_DWORD *)this + 121) = 2139095039;
  *((_DWORD *)this + 122) = 2139095039;
  *((_DWORD *)this + 123) = -8388609;
  *((_DWORD *)this + 124) = -8388609;
  *((_DWORD *)this + 125) = -8388609;
  if ( a3 )
  {
    v12 = *(_DWORD *)this;
    v20 = this + 480;
    if ( a3 == 1 )
      (*(void (__stdcall **)(char *, int))(v12 + 28))(v20, a2);
    else
      (*(void (__stdcall **)(char *, int))(v12 + 32))(v20, a2);
  }
  else
  {
    v6 = *((_DWORD *)this + 111);
    for ( i = 0; i < v6; ++i )
    {
      v8 = *(float **)(*((_DWORD *)this + 113) + 4 * i);
      v9 = *((_DWORD *)v8 + 29);
      v10 = v8[30];
      v11 = v8[31];
      v22 = v9;
      v23 = v10;
      v24 = v11;
      sub_5BC480(v5, (float *)&v22);
    }
  }
  if ( (_BYTE)a4 )
  {
    v13 = 0;
    v21 = *((_DWORD *)this + 108);
    if ( v21 > 0 )
    {
      do
      {
        v14 = *(_DWORD *)(*((_DWORD *)this + 110) + 4 * v13);
        v15 = a2;
        if ( a2 < 0 )
          v15 = 0;
        if ( v15 > *(_DWORD *)(v14 + 544) - 1 )
          v15 = *(_DWORD *)(v14 + 544) - 1;
        sub_5BC7F0(v15, a3, a4);
        v16 = (float *)(*(_DWORD *)(*((_DWORD *)this + 110) + 4 * v13) + 480);
        sub_5BC480(v5, v16);
        sub_5BC480(v5, v16 + 3);
        ++v13;
      }
      while ( v13 < v21 );
    }
  }
  v17 = v5[3] + *v5;
  v23 = v5[4] + v5[1];
  v24 = v5[5] + v5[2];
  v24 = v24 * 0.5;
  v18 = v17 * 0.5;
  v19 = v23 * 0.5;
  *((float *)this + 128) = v24;
  *((float *)this + 126) = v18;
  *((_DWORD *)this + 129) = 0;
  *((float *)this + 127) = v19;
  *((_DWORD *)this + 130) = 0;
  sub_5BC5A0((float *)this + 126, v5);
  sub_5BC5A0((float *)this + 126, (float *)this + 123);
}

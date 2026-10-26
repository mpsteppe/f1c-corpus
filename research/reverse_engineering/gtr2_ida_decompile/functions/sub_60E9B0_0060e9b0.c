float *__thiscall sub_60E9B0(_DWORD *this, int a2, char *a3, char a4)
{
  char *v4; // ebx
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  _DWORD *v10; // edx
  int v11; // edi
  int v12; // eax
  int v13; // ecx
  int v14; // ebx
  bool v15; // cc
  char *v16; // edi
  _DWORD **v17; // eax
  _DWORD *v18; // eax
  int v19; // ecx
  int v20; // eax
  _DWORD **v21; // eax
  bool v22; // zf
  int v24; // [esp+Ch] [ebp-34h]
  int v25; // [esp+10h] [ebp-30h]
  int v26; // [esp+20h] [ebp-20h]
  int v27; // [esp+24h] [ebp-1Ch]
  int v28; // [esp+28h] [ebp-18h] BYREF
  int v29; // [esp+2Ch] [ebp-14h] BYREF
  int v30; // [esp+30h] [ebp-10h]
  _DWORD *v31; // [esp+34h] [ebp-Ch]
  int v32; // [esp+38h] [ebp-8h]
  int v33; // [esp+3Ch] [ebp-4h]
  int v34; // [esp+44h] [ebp+4h]

  v4 = a3;
  sub_5E4DD0(a3, &v29, &v28);
  *(float *)&v25 = *(float *)&v28 + 0.001;
  *(float *)&v24 = *(float *)&v29 + 0.00050000002;
  sub_5E54E0((int)a3, v24, v25);
  sub_5E5050(a3, 262);
  (*(void (__thiscall **)(_DWORD *, int, int, int))(*this + 20))(this, 2304, 393221, 127);
  if ( !this[2412] )
  {
    sub_609BF0(6);
    sub_60A000(1);
    sub_60A790(this + 257);
    v6 = (*(int (__thiscall **)(_DWORD *))(*this + 532))(this);
    v7 = *this;
    this[1212] = 255 - v6;
    (*(void (__thiscall **)(_DWORD *, int, int))(v7 + 44))(this, 60, 255 - v6);
  }
  sub_60A500(0);
  sub_60A3A0(this + 705, 1);
  sub_60A3F0(this + 705, 1);
  v8 = this[2282];
  v26 = v8;
  if ( (int)this[2276] > 0 )
  {
    v27 = this[2276];
    do
    {
      v10 = *(_DWORD **)v8;
      v11 = **(_DWORD **)(*(_DWORD *)v8 + 776);
      v12 = 0;
      v31 = *(_DWORD **)v8;
      v33 = v11;
      v34 = 0;
      if ( v11 > 0 )
      {
        do
        {
          v13 = *(_DWORD *)(*(_DWORD *)(v10[194] + 4) + 4 * v12);
          v30 = *(_DWORD *)(v13 + 212);
          v14 = 0;
          v15 = *(_DWORD *)(v13 + 208) <= 0;
          v32 = v13;
          if ( !v15 )
          {
            do
            {
              v16 = *(char **)(v30 + 4 * v14);
              v17 = *(_DWORD ***)(a2 + 596);
              ++v14;
              *(_DWORD *)(a2 + 604) = v17;
              if ( v17 )
              {
                v18 = *v17;
                if ( v18 )
                {
                  do
                  {
                    if ( (*(_BYTE *)v18 & 4) != 0 )
                      v19 = *(_DWORD *)(v18[16] + 44);
                    else
                      v19 = v18[11];
                    sub_60E1A0(this, v19, (int)a3, v16, v18);
                    v20 = *(_DWORD *)(a2 + 604);
                    if ( !v20 )
                      break;
                    v21 = *(_DWORD ***)(v20 + 4);
                    *(_DWORD *)(a2 + 604) = v21;
                    if ( !v21 )
                      break;
                    v18 = *v21;
                  }
                  while ( v18 );
                  v10 = v31;
                  v13 = v32;
                }
              }
            }
            while ( v14 < *(_DWORD *)(v13 + 208) );
            v12 = v34;
            v11 = v33;
          }
          if ( a4 )
          {
            *(_BYTE *)(v13 + 200) = 0;
            *(_DWORD *)(v13 + 208) = 0;
          }
          v34 = ++v12;
        }
        while ( v12 < v11 );
        v8 = v26;
        v4 = a3;
      }
      if ( a4 )
      {
        *(_DWORD *)v8 = 0;
        *(_DWORD *)v10[194] = 0;
        v10[182] = 0;
        v10[200] = 0;
      }
      v8 += 4;
      v22 = v27 == 1;
      v26 = v8;
      --v27;
    }
    while ( !v22 );
  }
  sub_5E54E0((int)v4, v29, v28);
  return sub_5E5050(v4, 262);
}

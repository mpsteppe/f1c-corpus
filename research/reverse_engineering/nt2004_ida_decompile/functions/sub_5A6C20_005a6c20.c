int __thiscall sub_5A6C20(int *this, _DWORD *a2, char a3, _DWORD *a4, char a5, int a6)
{
  int v8; // ebx
  int v10; // edi
  char v11; // dl
  int i; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // [esp+10h] [ebp-Ch] BYREF
  int v21; // [esp+14h] [ebp-8h] BYREF
  _BYTE v22[4]; // [esp+18h] [ebp-4h] BYREF
  int v23; // [esp+28h] [ebp+Ch]

  sub_5B43F0(v22, a2[12], 0);
  v8 = (a4[14] & 0x800) != 0 ? -16777216 : -65281;
  if ( sub_5A6610((int)this, (int)a4, a4[11]) )
    return -1;
  if ( (a6 & 0x1000000) == 0 )
  {
    if ( (a4[14] & 0x4000) != 0 )
      v23 = a4[11];
    else
      v23 = 1;
    v10 = 0;
    if ( v23 > 0 )
    {
      v11 = a3;
      for ( i = a3 & 4; ; i = a3 & 4 )
      {
        if ( i && (v13 = a2[5]) != 0 || (v11 & 8) != 0 && (v13 = a2[6]) != 0 )
        {
          v14 = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v13 + 60))(v13, v10, &v20);
          *this = v14;
          if ( v14 )
            return -1;
        }
        else
        {
          if ( (v11 & 1) == 0 || (v15 = a2[3]) == 0 )
          {
            if ( (v11 & 2) == 0 )
              return -1;
            v15 = a2[4];
            if ( !v15 )
              return -1;
          }
          v20 = v15;
        }
        if ( (a5 & 4) != 0 && (v16 = a4[5]) != 0 || (a5 & 8) != 0 && (v16 = a4[6]) != 0 )
        {
          v17 = (*(int (__stdcall **)(int, int, int *))(*(_DWORD *)v16 + 60))(v16, v10, &v21);
          *this = v17;
          if ( v17 )
            return -1;
        }
        else
        {
          if ( (a5 & 1) == 0 || (v18 = a4[3]) == 0 )
          {
            if ( (a5 & 2) == 0 )
              return -1;
            v18 = a4[4];
            if ( !v18 )
              return -1;
          }
          v21 = v18;
        }
        v19 = sub_53D7A1(v21, 0, 0, v20, 0, 0, 4, v8);
        *this = v19;
        if ( v19 )
          return -1;
        if ( (a3 & 0xC) != 0 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v20 + 8))(v20);
        if ( (a5 & 0xC) != 0 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v21 + 8))(v21);
        if ( ++v10 >= v23 )
          break;
        v11 = a3;
      }
    }
    if ( (a4[14] & 0x2000) != 0 && (int)a4[11] > 1 )
      sub_53D9CD(a4[5], 0, 0xFFFFFFFF, 5);
  }
  return 0;
}

int __userpurge sub_496BF0@<eax>(int a1@<ecx>, int a2@<esi>, int a3, int a4)
{
  const char *v5; // eax
  int v6; // esi
  int v7; // ecx
  _DWORD *v8; // eax
  const CHAR *v9; // eax
  const CHAR *v10; // eax
  _DWORD *v11; // edx
  int v13; // [esp+0h] [ebp-1Ch]
  int v14; // [esp+4h] [ebp-18h]
  int v15; // [esp+4h] [ebp-18h]
  int v17; // [esp+10h] [ebp-Ch] BYREF
  _BYTE v18[4]; // [esp+14h] [ebp-8h] BYREF

  v5 = *(const char **)(a1 + 72);
  if ( !v5 )
    v5 = WindowName;
  if ( !strlen(v5) )
    return -1;
  v6 = *(_DWORD *)(a1 + 68);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)a1 + 4))(a1, a2);
  (*(void (__thiscall **)(int))(*(_DWORD *)a1 + 8))(a1);
  v7 = *(_DWORD *)(a1 + 48);
  v8 = *(_DWORD **)(v7 + 244);
  if ( v8 )
  {
    switch ( v6 )
    {
      case 0:
        if ( *(_BYTE *)(a1 + 65) )
          v9 = (const CHAR *)v8[20];
        else
          v9 = (const CHAR *)v8[16];
        break;
      case 2:
        if ( !*(_BYTE *)(a1 + 65) )
          goto LABEL_12;
        v9 = (const CHAR *)v8[20];
        break;
      case 3:
      case 4:
        v9 = (const CHAR *)v8[20];
        break;
      default:
LABEL_12:
        v9 = (const CHAR *)v8[18];
        break;
    }
    if ( v9 || (v9 = WindowName) != 0 )
    {
      sub_4DF1B0(*(_DWORD *)(v7 + 48), v9);
      v10 = *(const CHAR **)(a1 + 72);
      if ( !v10 )
        v10 = WindowName;
      sub_4E08C0(*(_DWORD *)(*(_DWORD *)(a1 + 48) + 48), v10, &v17, v18, 1, v14);
      if ( v13 > 0 && v15 > 0 )
      {
        v11 = *(_DWORD **)(a1 + 48);
        if ( !v11[39] && !v11[38] )
          return -1;
        sub_4E0730(v11[12]);
      }
    }
  }
  return 0;
}

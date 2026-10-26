int __thiscall sub_496E90(int this, __int16 a2)
{
  char v2; // bl
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  int **v8; // eax
  int *v9; // eax
  _DWORD *v10; // esi
  int i; // edi
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  int *v14; // eax
  double v15; // st7
  const char *v16; // esi
  __int16 v17; // [esp-10h] [ebp-2Ch]
  __int16 v18; // [esp-Ch] [ebp-28h]
  __int16 v19; // [esp-8h] [ebp-24h]
  char v20; // [esp-4h] [ebp-20h]
  __int16 v21; // [esp-4h] [ebp-20h]
  int v22; // [esp+10h] [ebp-Ch] BYREF
  __int16 v23; // [esp+14h] [ebp-8h] BYREF
  __int16 v24; // [esp+18h] [ebp-4h] BYREF

  v2 = a2;
  v20 = a2;
  *(_DWORD *)(this + 56) = 1;
  if ( sub_496030(this, v20) )
    return 0;
  v4 = *(_DWORD *)(this + 24);
  if ( v4 )
  {
    *(_DWORD *)(this + 52) = sub_498E40(v4);
    if ( dword_5CC9E8 != 5 )
      return -1;
    if ( (unsigned __int8)sub_497240(this) || dword_7CE03C || dword_5CC9E4 > 0 )
    {
      dword_5CC9E4 = (dword_5CC9E4 - 1) & ((dword_5CC9E4 - 1 <= 0) - 1);
      v8 = (int **)sub_490920();
      sub_4918D0(v8, 0, 0, 800, 600);
      sub_497250(0);
    }
    if ( !*(_BYTE *)(this + 36) )
    {
      v9 = (int *)sub_490920();
      sub_491BD0(v9);
      v10 = *(_DWORD **)(this + 24);
      for ( i = 0; i < 8; ++i )
      {
        if ( !v10[26] )
          break;
        (*(void (__thiscall **)(_DWORD *, __int16 *, __int16 *, int *, __int16 *))(*v10 + 8))(
          v10,
          &v24,
          &v23,
          &v22,
          &a2);
        v21 = v23 - v24;
        v19 = a2 - v22;
        v18 = v24;
        v17 = v22;
        v12 = (_DWORD *)sub_490920();
        sub_4919C0(v12, v17, v18, v19, v21);
        v10 = (_DWORD *)v10[26];
      }
      while ( v10 )
      {
        v13 = (_DWORD *)sub_490920();
        sub_491AD0(v13);
        (*(void (__thiscall **)(_DWORD *))(*v10 + 52))(v10);
        v10 = (_DWORD *)v10[25];
        v14 = (int *)sub_490920();
        sub_491A40(v14);
      }
      sub_495B60(this);
      sub_495BD0((char *)this);
      sub_4973D0(this);
      sub_495580(this);
    }
    v15 = *(float *)(this + 68);
    *(_DWORD *)(this + 56) = 2;
    if ( v15 > 0.0 )
    {
      v16 = *(const char **)(this + 60);
      if ( !v16 )
        v16 = byte_5EA438;
      if ( sub_423A00(byte_5EC4C0, v16, byte_5EC4CC) )
      {
        if ( v16 )
          strcpy(byte_5EC4CC, v16);
        else
          byte_5EC4CC[0] = 0;
      }
      sub_4989E0(byte_5EC4CC);
      *(float *)(this + 68) = *(float *)(this + 68) - sub_498730(this);
    }
    sub_497100(1);
    *(_BYTE *)(this + 36) = 0;
    return 0;
  }
  v5 = sub_495150();
  sub_494BF0(v5, 0, 0, *(_DWORD *)(v5 + 28), *(_DWORD *)(v5 + 32), 656386);
  if ( strlen((const char *)(this + 5740)) )
  {
    v6 = sub_495150();
    sub_494F10(this + 5740, aNoDrawStackAva, 0, 0, v6, 1);
  }
  sub_497100(v2);
  return -1;
}

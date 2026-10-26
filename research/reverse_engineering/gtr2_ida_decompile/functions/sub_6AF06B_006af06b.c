int __thiscall sub_6AF06B(void *this, int a2, unsigned int *a3, _DWORD *a4, int *a5)
{
  int v6; // ebx
  unsigned int v7; // eax
  int v9; // [esp+Ch] [ebp-4h]

  v9 = 1;
  v6 = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 84))(this, *(_DWORD *)(a2 + 108));
  v7 = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 88))(this, *(_DWORD *)(a2 + 108));
  *a3 = v7;
  if ( v6 != 11 )
  {
    if ( v6 == 13 )
    {
      if ( !v7 )
      {
        *a4 = 9;
        goto LABEL_9;
      }
    }
    else if ( v6 == 0xFFFF )
    {
      *a4 = 0;
      v9 = 0;
      goto LABEL_9;
    }
    return -2147467259;
  }
  if ( v7 >= 4 )
    return -2147467259;
  *a4 = 8;
LABEL_9:
  if ( a5 )
    *a5 = v9;
  return 0;
}

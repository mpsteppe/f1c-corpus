int __thiscall sub_6CD068(int this)
{
  int result; // eax
  int v3; // [esp+8h] [ebp-8h] BYREF
  int v4; // [esp+Ch] [ebp-4h] BYREF

  switch ( **(_DWORD **)(this + 256) & 0xFFFFF )
  {
    case 1:
      return sub_6CCA8D((_DWORD *)this, 5, 0);
    case 3:
      return sub_6CCA8D((_DWORD *)this, 8, 0);
    case 4:
      return sub_6CCA8D((_DWORD *)this, 9, 0);
  }
  result = (*(int (__thiscall **)(int, _DWORD, int *, int, _DWORD, _DWORD))(*(_DWORD *)this + 128))(
             this,
             *(_DWORD *)(this + 252),
             &v3,
             2,
             0,
             0);
  if ( result >= 0 )
  {
    result = sub_6CB29C(
               (_DWORD *)this,
               5,
               &v3,
               2,
               *(_DWORD **)(*(_DWORD *)(this + 256) + 8),
               (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 8) + 8),
               0,
               2,
               0,
               0,
               0,
               0);
    if ( result >= 0 )
    {
      result = sub_6CB29C(
                 (_DWORD *)this,
                 2,
                 *(_DWORD **)(*(_DWORD *)(this + 256) + 16),
                 *(_DWORD *)(*(_DWORD *)(this + 256) + 12),
                 &v3,
                 &v4,
                 0,
                 1,
                 0,
                 0,
                 0,
                 0);
      if ( result >= 0 )
        return 0;
    }
  }
  return result;
}

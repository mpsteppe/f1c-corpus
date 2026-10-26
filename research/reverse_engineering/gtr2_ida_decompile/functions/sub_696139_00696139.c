int __thiscall sub_696139(_DWORD *this)
{
  int v2; // eax
  int result; // eax
  int v4; // ecx
  int i; // edi
  int v6; // eax

  v2 = this[4];
  if ( v2 )
  {
    if ( *(_DWORD *)(v2 + 16) == 4 )
    {
      v4 = *(_DWORD *)(v2 + 32);
      if ( v4 )
      {
        if ( *(_DWORD *)(v4 + 16) != 4 )
        {
          for ( i = v2 + 24; *(_DWORD *)i; i = *(_DWORD *)i + 12 )
          {
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)i + 8) + 44) = 1;
            result = sub_694D2B(*(_DWORD *)(this[4] + 32), *(_DWORD *)(*(_DWORD *)i + 8));
            if ( result < 0 )
              return result;
          }
          *(_DWORD *)i = *(_DWORD *)(*(_DWORD *)(this[4] + 32) + 24);
          *(_DWORD *)(*(_DWORD *)(this[4] + 32) + 24) = *(_DWORD *)(this[4] + 24);
          *(_DWORD *)(this[4] + 24) = 0;
        }
      }
    }
    v6 = this[4];
    this[4] = *(_DWORD *)(v6 + 32);
    *(_DWORD *)(v6 + 32) = 0;
    return 0;
  }
  else
  {
    sub_694C3A(this, 0, 0, "internal error: scope underflow");
    return -2147467259;
  }
}

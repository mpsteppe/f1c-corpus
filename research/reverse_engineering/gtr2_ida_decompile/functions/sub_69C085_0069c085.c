_DWORD *__thiscall sub_69C085(_DWORD *this, unsigned int a2, _DWORD *a3)
{
  unsigned int v3; // esi
  _DWORD *v5; // eax

  v3 = a2;
  if ( a2 )
  {
    if ( sub_69BE34(this, a3, &a2) >= 0 )
    {
      if ( a2 && a2 <= 4 )
      {
        v5 = (_DWORD *)sub_65B229(36);
        if ( v5 )
          return sub_67F2D4(v5, 1, *(_DWORD *)(v3 + 20), 1, a2, 0);
      }
      else
      {
        sub_694B97((int)this, (int)(this + 8), 3052, "vector dimension must be between 1 and %u", 4);
      }
    }
    else
    {
      sub_694B97((int)this, (int)(this + 8), 3060, "vector dimension must be a literal scalar expression");
    }
  }
  return 0;
}

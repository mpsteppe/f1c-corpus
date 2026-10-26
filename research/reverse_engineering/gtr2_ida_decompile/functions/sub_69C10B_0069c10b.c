_DWORD *__thiscall sub_69C10B(_DWORD *this, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  unsigned int v4; // edi
  _DWORD *v6; // eax

  v4 = a2;
  if ( a2 )
  {
    if ( sub_69BE34(this, a3, &a3) < 0 || sub_69BE34(this, a4, &a2) < 0 )
    {
      sub_694B97((int)this, (int)(this + 8), 3061, "matrix dimensions must be literal scalar expressions");
    }
    else if ( a3 && (unsigned int)a3 <= 4 && a2 && a2 <= 4 )
    {
      v6 = (_DWORD *)sub_65B229(36);
      if ( v6 )
        return sub_67F2D4(v6, 2, *(_DWORD *)(v4 + 20), (int)a3, a2, 0);
    }
    else
    {
      sub_694B97((int)this, (int)(this + 8), 3053, "matrix dimensions must be between 1 and %u", 4);
    }
  }
  return 0;
}

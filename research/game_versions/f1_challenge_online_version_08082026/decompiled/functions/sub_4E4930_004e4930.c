int __thiscall sub_4E4930(int this, float *a2)
{
  int v3; // eax
  int v4; // eax
  int result; // eax

  v3 = *(_DWORD *)(this + 12988);
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      result = v4 - 1;
      if ( !result )
      {
        *(float *)(this + 13484) = *(float *)&a2;
        return sub_4F03E0(*(float *)&a2);
      }
    }
    else
    {
      sub_4A6E50(this + 12992, a2);
      return sub_4E4E60(a2);
    }
  }
  else
  {
    sub_4A6E50(this + 12992, a2);
    sub_441650((int *)&dbl_7C7428, *(float *)&a2);
    *(float *)(this + 13484) = *(float *)&a2;
    return sub_4E49B0(this);
  }
  return result;
}

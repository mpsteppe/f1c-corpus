double __thiscall sub_41DA00(_DWORD *this, char *String1)
{
  const char *v2; // eax

  v2 = sub_41D920(this, String1);
  if ( v2 && *((float *)v2 + 18) >= 0.0 )
    return *((float *)v2 + 18);
  else
    return 0.0;
}

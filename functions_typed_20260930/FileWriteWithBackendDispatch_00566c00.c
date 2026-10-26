int __thiscall sub_566C00(int *this, int a2, int a3)
{
  if ( this[4] )
    return BufferedFileReader(*this, a2, a3);
  else
    return ThreadSafeReadWrapper_803f(a2, 1, a3, *this);
}


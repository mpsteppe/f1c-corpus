void __thiscall StringPathResolutionWithFallback(_DWORD *this, const char *a2, int a3)
{
  const char *v3; // edx
  unsigned int v5; // kr04_4
  signed int v6; // eax
  char v7; // bl

  v3 = a2;
  if ( !a2 )
    goto LABEL_10;
  v5 = strlen(a2) + 1;
  if ( (int)(v5 - 1) > 27 )
  {
    v6 = v5 - 29;
    if ( (int)(v5 - 29) < (int)(v5 - 1) )
    {
      do
        v7 = a2[v6++];
      while ( v7 != 32 && v6 < (int)(v5 - 1) );
    }
    v3 = &a2[v6];
  }
  if ( v3 && *v3 )
    LinkedListInsertWithNodeAllocation(this, (int)v3, -1);
  else
LABEL_10:
    LinkedListInsertWithNodeAllocation(this, a3, -1);
}

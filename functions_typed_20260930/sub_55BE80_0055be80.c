int __thiscall sub_55BE80(unsigned int **this, int a2, int a3)
{
  int v4; // edi
  int result; // eax
  unsigned int **i; // esi
  _DWORD *v7; // eax
  unsigned int *v8; // eax
  int v9; // edx
  unsigned int *v10; // esi

  *this = 0;
  this[1] = 0;
  sub_53D970(dword_8B78A0, a3);
  v4 = 0;
  result = FieldAccessor(dword_8B78A0);
  if ( result > 0 )
  {
    for ( i = this + 2; ; ++i )
    {
      v7 = (_DWORD *)OperatorNewNhMallocWrapper(292);
      v8 = v7 ? DualFieldSetToSameValue(v7, v4) : 0;
      *i = v8;
      result = PartialStructZeroInit(v8);
      if ( result )
        break;
      strcpy((char *)*i + 4, (const char *)(IndexedArrayAccess_d890(dword_8B78A0, v4) + 24));
      (*i)[65] = v4;
      (*i)[66] = 0;
      (*i)[67] = 0;
      DisplayModeEnumeratorWrapper(*i);
      v9 = (int)*this + 1;
      this[1] = (unsigned int *)((char *)this[1] + 1);
      *this = (unsigned int *)v9;
      ++v4;
      result = FieldAccessor(dword_8B78A0);
      if ( v4 >= result )
        return result;
    }
    v10 = this[v4 + 2];
    if ( v10 )
    {
      EmptyStub_7470(this[v4 + 2]);
      result = FreeWrapper_7bcf(v10);
    }
    this[v4 + 2] = 0;
  }
  return result;
}


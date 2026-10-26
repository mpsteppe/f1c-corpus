// f1c  0x00404e60  size=136
int __thiscall sub_404E60(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // esi
  int v5; // edi
  int *v6; // esi

  result = sub_587C03(8);
  v4 = result;
  if ( result )
  {
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 4) = -1;
    result = sub_566650(a2);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = (int *)(*this + 64);
  if ( v5 )
  {
    result = sub_587C03(12);
    if ( result )
    {
      *(_DWORD *)result = v5;
      *(_DWORD *)(result + 4) = 0;
      *(_BYTE *)(result + 8) = 1;
    }
    else
    {
      result = 0;
    }
    if ( *v6 )
    {
      *(_DWORD *)(v6[1] + 4) = result;
      v6[1] = result;
      ++v6[3];
    }
    else
    {
      *v6 = result;
      v6[2] = result;
      v6[1] = result;
      result = v6[3] + 1;
      v6[3] = result;
    }
  }
  return result;
}

char __thiscall sub_4C0690(int *this, _DWORD *a2, int a3)
{
  int v4; // edi
  int *v5; // ebx

  if ( *a2 )
  {
    if ( a3 )
    {
      ResourceLookupWithDualPath(a3);
      ResourceLookupWithDualPath(&word_5C30B4);
    }
    BufferWriteWithStringLengthCheck(a2, aNameS);
    BufferWriteWithStringLengthCheck(a2, aVehfileS);
    BufferWriteWithStringLengthCheck(a2, aRcdfileS);
    v4 = 0;
    v5 = this + 6;
    do
    {
      if ( *v5 < 0 )
        break;
      BufferWriteWithStringLengthCheck(a2, aFinishposition_0);
      BufferWriteWithStringLengthCheck(a2, aFinishpoints22);
      ++v4;
      ++v5;
    }
    while ( v4 < 48 );
    BufferWriteWithStringLengthCheck(a2, aSeasonpointsD);
    BufferWriteWithStringLengthCheck(a2, aPointsposition_0);
    BufferWriteWithStringLengthCheck(a2, aPolestakenD);
    BufferWriteWithStringLengthCheck(a2, aOriginalgridpo_0);
    BufferWriteWithStringLengthCheck(a2, aCurrentgridpos_0);
    BufferWriteWithStringLengthCheck(a2, aControltypeD);
    BufferWriteWithStringLengthCheck(a2, aActiveD);
    BufferWriteWithStringLengthCheck(a2, &word_5C30B4);
  }
  return 0;
}


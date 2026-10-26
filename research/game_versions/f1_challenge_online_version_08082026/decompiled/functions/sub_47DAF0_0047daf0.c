_DWORD *__thiscall sub_47DAF0(_DWORD *this, int a2)
{
  sub_488B00(1, -1);
  *this = &off_5A6B20;
  this[59] = a2;
  if ( a2 == 480 )
  {
    sub_486F30(aBegin, -1);
    sub_486F30(&off_5C7364, -1);
    sub_486F30(aReverseScanFas, -1);
    sub_486F30(aReverseScan, -1);
    sub_486F30(aPlaybackwards, -1);
    sub_486F30(aStop, -1);
    sub_486F30(aPlay, -1);
    sub_486F30(aForwardScan, -1);
    sub_486F30(aForwardScanFas, -1);
    sub_486F30(aDropBookmark, -1);
    sub_486F30(aRemoveBookmark, -1);
  }
  return this;
}

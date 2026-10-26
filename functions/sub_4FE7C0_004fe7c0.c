int __thiscall sub_4FE7C0(float *this, int a2)
{
  _DWORD *v3; // eax
  int v5; // esi
  _BYTE v6[56]; // [esp+4h] [ebp-38h] BYREF

  StructZeroInit_7a00(v6);
  AudioFileLoadDecode(a2, 0);
  v3 = (_DWORD *)AudioChannelStop(aWeather_1);
  if ( v3 )
  {
    v5 = sub_4FE350(this, v3);
    LinkedListDestructorWithInnerFree(v6);
    return v5;
  }
  else
  {
    LinkedListDestructorWithInnerFree(v6);
    return -1;
  }
}

int __thiscall sub_52E090(int this, unsigned int a2, int a3)
{
  int v5; // eax
  int v6; // ecx

  if ( *(_BYTE *)(this + 9452) )
    sub_52E320();
  *(_BYTE *)(this + 9452) = 1;
  *(_DWORD *)(this + 9380) = 0;
  *(_DWORD *)(this + 9456) = a2;
  if ( sub_52DE40((void *)this, a2) )
  {
    off_5DA714(aAudioAssert);
    off_5DA714("%s(%d) : %s\n", aDDevAudiodevSh, 1698, aCmpegbaseOpenG);
    off_5DA718();
    return -1;
  }
  else
  {
    sub_52DA10(this);
    sub_52DE60(this);
    sub_52E2F0(this);
    v5 = sub_52E080(
           a3 + *(_DWORD *)(this + 9428),
           *(_DWORD *)(this + 9440),
           *(_DWORD *)(this + 9428) * (*(_DWORD *)(this + 9436) + *(_DWORD *)(this + 9440) * *(_DWORD *)(this + 9432)));
    v6 = v5 * *(_DWORD *)(this + 9356);
    *(_DWORD *)(this + 9376) = v5;
    *(_DWORD *)(this + 9392) = v6;
    return 0;
  }
}

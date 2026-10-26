int __thiscall sub_52F6F0(int this, unsigned int a2, int a3)
{
  int v5; // eax
  int v6; // ecx

  if ( *(_BYTE *)(this + 9452) )
    sub_52F980((void *)this);
  *(_BYTE *)(this + 9452) = 1;
  *(_DWORD *)(this + 9380) = 0;
  *(_DWORD *)(this + 9456) = a2;
  if ( sub_52F4A0((void *)this, a2) )
  {
    off_61591C(aAudioAssert);
    off_61591C("%s(%d) : %s\n", aDDevAudiodevSh, 1698, aCmpegbaseOpenG);
    off_615920();
    return -1;
  }
  else
  {
    sub_52F070(this);
    sub_52F4C0(this);
    sub_52F950(this);
    v5 = sub_52F6E0(
           a3 + *(_DWORD *)(this + 9428),
           *(_DWORD *)(this + 9440),
           *(_DWORD *)(this + 9428) * (*(_DWORD *)(this + 9436) + *(_DWORD *)(this + 9440) * *(_DWORD *)(this + 9432)));
    v6 = v5 * *(_DWORD *)(this + 9356);
    *(_DWORD *)(this + 9376) = v5;
    *(_DWORD *)(this + 9392) = v6;
    return 0;
  }
}

int __thiscall sub_52F830(int this, unsigned int a2, int a3)
{
  int v4; // eax
  int v6; // eax
  int v7; // ecx

  if ( *(_BYTE *)(this + 9452) )
    sub_52F980((void *)this);
  v4 = this + 9523;
  *(_BYTE *)(this + 9452) = 1;
  LOBYTE(v4) = (this + 51) & 0xC0;
  *(_DWORD *)(this + 9380) = v4;
  if ( a2 )
  {
    if ( sub_52F4A0((void *)this, _byteswap_ulong(a2)) )
    {
      off_61591C(aAudioAssert);
      off_61591C("%s(%d) : %s\n", aDDevAudiodevSh, 1736, aCmpegfileplaye_0);
LABEL_8:
      off_615920();
      return -1;
    }
  }
  else if ( (*(int (__thiscall **)(int))(*(_DWORD *)this + 12))(this) )
  {
    off_61591C(aAudioAssert);
    off_61591C("%s(%d) : %s\n", aDDevAudiodevSh, 1744, aCmpegfileplaye_1);
    goto LABEL_8;
  }
  sub_52F070(this);
  sub_52F4C0(this);
  sub_52F950(this);
  v6 = sub_52F6E0(
         a3 + *(_DWORD *)(this + 9428),
         *(_DWORD *)(this + 9440),
         *(_DWORD *)(this + 9428) * (*(_DWORD *)(this + 9436) + *(_DWORD *)(this + 9440) * *(_DWORD *)(this + 9432)));
  *(_DWORD *)(this + 9392) = v6 * *(_DWORD *)(this + 9356);
  v7 = *(_DWORD *)(this + 11572);
  *(_DWORD *)(this + 9376) = v6;
  (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v7 + 12))(v7, *(_DWORD *)(this + 11576), 0);
  *(_BYTE *)(this + 11580) = 1;
  return 0;
}

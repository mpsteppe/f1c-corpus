int __thiscall sub_565890(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // [esp+10h] [ebp-4h] BYREF

  v6 = 0;
  if ( *((_DWORD *)dword_91E07C + 4874) )
  {
    *(_BYTE *)(this + 24) = 1;
    v2 = *((_DWORD *)dword_91E07C + 4874);
    *(_DWORD *)(this + 28) = v2;
    v3 = ((int (__thiscall *)(void *, int, char *, int, int *))loc_4E4BE0)(
           &unk_B6E79C,
           v2,
           dword_91E07C,
           this + 20,
           &v6);
  }
  else
  {
    if ( !*((_DWORD *)dword_91E07C + 4875) )
      goto LABEL_6;
    *(_BYTE *)(this + 24) = 0;
    v4 = *((_DWORD *)dword_91E07C + 4875);
    *(_DWORD *)(this + 28) = v4;
    v3 = ((int (__thiscall *)(void *, char *, int, int, int *))loc_4E4BE0)(
           &unk_B6E79C,
           dword_91E07C,
           v4,
           this + 20,
           &v6);
  }
  if ( v3 )
    return sub_561A50((int *)this);
LABEL_6:
  if ( *(float *)(this + 20) <= 0.0 )
    return sub_561A50((int *)this);
  result = v6;
  if ( v6 )
    return sub_561A50((int *)this);
  return result;
}

int __thiscall sub_54D140(int this, float a2)
{
  int v3; // eax
  int v4; // edi
  int result; // eax
  float v6; // [esp+4h] [ebp-4h]

  v3 = *(_DWORD *)(this + 8);
  if ( v3 )
  {
    if ( v3 != 1 || !*(_DWORD *)(this + 52) )
      goto LABEL_9;
    v4 = *(_DWORD *)(this + 56);
  }
  else
  {
    if ( !*(_DWORD *)(this + 212) )
      goto LABEL_9;
    v4 = *(_DWORD *)(this + 216);
  }
  if ( (unsigned __int8)sub_405250() )
  {
    v6 = (a2 + 1.0) * 0.5;
    *(double *)v4 = *(float *)(*(_DWORD *)(v4 + 60) + 20) * v6;
  }
LABEL_9:
  result = LODWORD(a2);
  *(float *)(this + 12) = a2;
  return result;
}

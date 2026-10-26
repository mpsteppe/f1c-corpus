unsigned int __thiscall sub_4EF5A0(float *this, _DWORD *a2, char a3)
{
  unsigned int result; // eax
  _DWORD *v5; // edi
  unsigned int v6; // edi
  int v7; // eax
  float v8; // esi
  _BYTE v9[12]; // [esp+8h] [ebp-30h] BYREF
  _BYTE v10[12]; // [esp+14h] [ebp-24h] BYREF
  double v11[3]; // [esp+20h] [ebp-18h] BYREF

  result = (unsigned int)a2;
  v5 = (_DWORD *)*((_DWORD *)this + 3247);
  *((_DWORD *)this + 3247) = a2;
  if ( !a3 )
  {
LABEL_6:
    if ( dword_7C569C != 5 )
      return result;
    goto LABEL_7;
  }
  if ( dword_7C569C != 5 )
    return result;
  if ( !a2 && v5 )
  {
    F_3DTransformWithMatrixMultiplication(v10, v9);
    AIVehiclePathPositionTracking(v10, v9);
    v11[0] = this[3387];
    v11[1] = this[3388];
    v11[2] = this[3389];
    result = sub_447780((int)&dbl_7C7428, v11);
    goto LABEL_6;
  }
LABEL_7:
  if ( v5 != (_DWORD *)1 && *((_DWORD *)this + 3247) == 1 )
  {
    v6 = 0;
    v7 = PositionChangeMonitor(this);
    if ( v7 )
      v6 = *(_DWORD *)(v7 + 300);
    SessionCleanupFlagClear(*(_DWORD *)this);
    result = AISpeedDeltaSetter(*(_DWORD **)this, v6);
    v8 = *this;
    *(_DWORD *)(LODWORD(v8) + 17236) = 0;
    *(_DWORD *)(LODWORD(v8) + 17240) = 0;
  }
  return result;
}

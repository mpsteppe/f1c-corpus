char __thiscall sub_40F1C0(int this, float a2)
{
  char v3; // bl
  char result; // al
  _DWORD *v5; // ecx

  switch ( *(_DWORD *)(this + 28) )
  {
    case 0:
    case 3:
      v3 = sub_45A8E0(LODWORD(a2), this + 12);
      if ( v3 )
        goto LABEL_12;
      goto LABEL_7;
    case 1:
    case 4:
      v3 = sub_45A8E0(LODWORD(a2), this + 12);
      if ( !v3 )
        goto LABEL_7;
      goto LABEL_12;
    case 2:
    case 5:
      v3 = sub_45A8E0(LODWORD(a2), this + 12);
      if ( v3 )
        goto LABEL_12;
LABEL_7:
      CameraShakeRingBufferWrite(this);
      sub_4BDE20(this);
      result = 0;
      break;
    case 6:
      if ( (*(_DWORD *)(**(_DWORD **)(this + 32) + 18620) & 8) != 0 )
        VehiclePhysicsModeDispatcher(a2);
      SuspensionStateUpdate(*(_DWORD *)(this + 32));
      v5 = (_DWORD *)(*(_DWORD *)(this + 32) + 13524);
      *(_DWORD *)(this + 12) = *v5;
      *(_DWORD *)(this + 16) = v5[1];
      *(_DWORD *)(this + 20) = v5[2];
      sub_4BDE20(this);
      return 1;
    default:
      v3 = 0;
LABEL_12:
      sub_4BDE20(this);
      result = v3;
      break;
  }
  return result;
}


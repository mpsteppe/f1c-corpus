char __thiscall sub_418510(int this, float a2)
{
  char v3; // bl
  char result; // al
  _DWORD *v5; // eax

  switch ( *(_DWORD *)(this + 32) )
  {
    case 0:
    case 3:
      v3 = sub_471FC0(LODWORD(a2), this + 16, 0);
      if ( v3 )
        goto LABEL_14;
      goto LABEL_9;
    case 1:
    case 6:
      v3 = sub_471FC0(LODWORD(a2), this + 16, 0);
      if ( !v3 )
        goto LABEL_9;
      goto LABEL_14;
    case 2:
      v3 = sub_471FC0(LODWORD(a2), this + 16, 0);
      if ( !v3 )
        goto LABEL_9;
      goto LABEL_14;
    case 4:
    case 5:
      v3 = sub_471FC0(LODWORD(a2), this + 16, byte_B731B0);
      if ( v3 )
        goto LABEL_14;
LABEL_9:
      sub_416B10();
      sub_52FAB0(this);
      result = 0;
      break;
    case 7:
      if ( (*(_DWORD *)(**(_DWORD **)(this + 36) + 22580) & 8) != 0 )
        sub_5840D0(a2);
      sub_5732F0(*(_DWORD *)(this + 36));
      v5 = (_DWORD *)(*(_DWORD *)(this + 36) + 15972);
      *(_DWORD *)(this + 16) = *v5;
      *(_DWORD *)(this + 20) = v5[1];
      *(_DWORD *)(this + 24) = v5[2];
      sub_52FAB0(this);
      return 1;
    default:
      v3 = 0;
LABEL_14:
      sub_52FAB0(this);
      result = v3;
      break;
  }
  return result;
}

char __thiscall sub_4162B0(_DWORD *this, float a2)
{
  char v3; // bl
  char result; // al
  int v5; // ecx
  _DWORD *v6; // ecx

  switch ( this[8] )
  {
    case 0:
    case 3:
      v3 = sub_45BA00(LODWORD(a2), this + 4);
      if ( v3 )
        goto LABEL_13;
      goto LABEL_7;
    case 1:
    case 4:
      v3 = sub_45BA00(LODWORD(a2), this + 4);
      if ( !v3 )
        goto LABEL_7;
      goto LABEL_13;
    case 2:
    case 5:
      v3 = sub_45BA00(LODWORD(a2), this + 4);
      if ( v3 )
        goto LABEL_13;
LABEL_7:
      sub_416750(this);
      sub_4E0610(this);
      result = 0;
      break;
    case 6:
      v5 = this[9];
      if ( (*(_DWORD *)(*(_DWORD *)v5 + 25296) & 8) != 0 || *(_DWORD *)(*(_DWORD *)v5 + 16584) == 2 )
        sub_50FD30(a2);
      sub_514EB0(this[9]);
      v6 = (_DWORD *)(this[9] + 17520);
      this[4] = *v6;
      this[5] = v6[1];
      this[6] = v6[2];
      sub_4E0610(this);
      return 1;
    default:
      v3 = 0;
LABEL_13:
      sub_4E0610(this);
      result = v3;
      break;
  }
  return result;
}

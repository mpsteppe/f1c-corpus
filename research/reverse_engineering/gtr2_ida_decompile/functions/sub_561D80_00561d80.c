void *__stdcall sub_561D80(int a1)
{
  int *v1; // esi
  void *result; // eax

  switch ( a1 )
  {
    case 1:
      v1 = &dword_FAE930;
      goto LABEL_13;
    case 2:
      v1 = &dword_FAE934;
      goto LABEL_13;
    case 3:
      v1 = &dword_FAE938;
      goto LABEL_13;
    case 4:
      v1 = &dword_FAE93C;
      goto LABEL_13;
    case 5:
      v1 = &dword_FAE944;
      goto LABEL_13;
    case 6:
      v1 = &dword_FAE940;
      goto LABEL_13;
    case 7:
      v1 = &dword_FAE948;
      goto LABEL_13;
    case 8:
      v1 = (int *)&flt_FAE950;
      goto LABEL_13;
    case 9:
      v1 = &dword_FAE960;
      goto LABEL_13;
    case 10:
      v1 = &dword_FAE94C;
      goto LABEL_13;
    case 11:
      v1 = &dword_FAE96C;
LABEL_13:
      if ( *v1 )
      {
        sub_5EE1D0(dword_FB1CE0, *v1);
        *v1 = 0;
      }
      break;
    default:
      break;
  }
  result = (void *)(a1 - 3);
  switch ( a1 )
  {
    case 3:
      result = dword_FAE954;
      if ( dword_FAE954 )
      {
        result = (void *)sub_5E4BF0(dword_FB1CE0, dword_FAE954);
        dword_FAE954 = 0;
      }
      break;
    case 4:
      result = dword_FAE958;
      if ( dword_FAE958 )
      {
        result = (void *)sub_5E4BF0(dword_FB1CE0, dword_FAE958);
        dword_FAE958 = 0;
      }
      break;
    case 6:
      result = dword_FAE95C;
      if ( dword_FAE95C )
      {
        result = (void *)sub_5E4BF0(dword_FB1CE0, dword_FAE95C);
        dword_FAE95C = 0;
      }
      break;
    case 7:
      result = dword_FAE974;
      if ( dword_FAE974 )
      {
        result = (void *)sub_5E4BF0(dword_FB1CE0, dword_FAE974);
        dword_FAE974 = 0;
      }
      break;
    case 9:
      result = dword_FAE964;
      if ( dword_FAE964 )
      {
        result = (void *)sub_5E4BF0(dword_FB1CE0, dword_FAE964);
        dword_FAE964 = 0;
      }
      break;
    case 10:
      result = dword_FAE968;
      if ( dword_FAE968 )
      {
        result = (void *)sub_5E4BF0(dword_FB1CE0, dword_FAE968);
        dword_FAE968 = 0;
      }
      break;
    case 11:
      result = dword_FAE970;
      if ( dword_FAE970 )
      {
        result = (void *)sub_5E4BF0(dword_FB1CE0, dword_FAE970);
        dword_FAE970 = 0;
      }
      break;
    default:
      return result;
  }
  return result;
}

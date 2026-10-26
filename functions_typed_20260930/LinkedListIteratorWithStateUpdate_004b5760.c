int *__thiscall sub_4B5760(int this)
{
  int *result; // eax
  int i; // esi
  int v4[108]; // [esp+8h] [ebp-1B0h] BYREF

  result = *(int **)(this + 32);
  *(_DWORD *)(this + 40) = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      if ( (unsigned __int8)FieldCompareConstant(i)
        && (unsigned __int8)FloatComparisonCheck(i)
        && (unsigned __int8)AudioSamplePlaybackWithPitchModulationAndStereoP(*(float *)(this + 48), (int)v4) )
      {
        *(float *)(i + 880) = *(float *)&v4[1];
        SceneNodeDecoder(dword_5EA560, (int)v4);
      }
      result = *(int **)(this + 40);
      if ( !result )
        break;
      result = (int *)result[1];
      *(_DWORD *)(this + 40) = result;
      if ( !result )
        break;
    }
  }
  return result;
}


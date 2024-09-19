#ifndef BIDIRECTIONAL_MAP_N_HEADER
#define BIDIRECTIONAL_MAP_N_HEADER
#include <unordered_map>

template<typename typeKey, typename typeValue>
class BidirectionalMap
{
private:
    std::unordered_map<typeKey, typeValue> _keyToValue;
    std::unordered_map<typeValue, typeKey> _valueToKey;
public:
    inline typeValue GetValue(typeKey key)
    {
        return _keyToValue[key];
    }

    inline typeKey GetKey(typeValue value)
    {
        return _valueToKey[value];
    }

    void SetValue(typeKey key, typeValue value)
    {
        _keyToValue[key] = value;
        _valueToKey[value] = key;
    }
};

#endif // !BIDIRECTIONAL_MAP_N_HEADER

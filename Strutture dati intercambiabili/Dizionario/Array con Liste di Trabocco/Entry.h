#ifndef DIZENTRY_H
#define DIZENTRY_H

// E=tipo elemento, K=tipo chiave
template<typename K, typename V> class Entry {
public:
	Entry(K, V); // costruttore
	Entry(); // costruttore
	V get_value(); // restituisce il valore dell'attributo
	K get_key(); // restituisce la chiave
	void set_value(V&);
	void set_key(K); // restituisce la chiave

	Entry(const Entry<K, V> &);
	Entry<K, V>& operator=(const Entry<K, V> &);
private:
	K chiave;
	V valore;
};

template<typename K, typename V> Entry<K, V>::Entry() {
}

template<typename K, typename V> Entry<K, V>::Entry(const Entry<K, V> & e) {
	chiave = e.chiave;
	valore = e.valore;
}

template<typename K, typename V> Entry<K, V>& Entry<K, V>::operator=(
		const Entry<K, V> & e) {
	chiave = e.chiave;
	valore = e.valore;
	return *this;
}

template<typename K, typename V> Entry<K, V>::Entry(K k, V v) {
	chiave = k;
	valore = v;
}

template<typename K, typename V> K Entry<K, V>::get_key() {
	return chiave;
}

template<typename K, typename V> V Entry<K, V>::get_value() {
	return valore;
}

template<typename K, typename V> void Entry<K, V>::set_key(K k) {
	chiave = k;
}

template<typename K, typename V> void Entry<K, V>::set_value(V &v) {
	valore = v;
}

#endif // _DIZENTRY_H

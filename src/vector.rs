// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   vector.rs                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lumugot <lumugot@42angouleme.fr>           +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2026/04/25 15:39:05 by lumugot           #+#    #+#             //
//   Updated: 2026/04/25 15:46:58 by lumugot          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

use std::fmt;

pub struct Vector<K> {
	pub data:	Vec<K>,
}

impl<K: Clone> Vector<K> {
	pub fn from(data: &[K]) -> Self
	{
		Vector { data: data.to_vec() }
	}

	pub fn size(&self) -> usize
	{
		self.data.len()
	}
}

impl<K: fmt::Display>	fmt::Display for Vector<K> {
	fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result
	{
		for x in &self.data
		{
			writeln!(f, "[{}]", x)?;
		}
		Ok(())
	}
}
